#include "HomeWindow.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QStackedLayout>

#include "CommandSimulator.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow( parent )
{
    for( size_t index = 0; index < MaxUser; ++index )
    {
        profilPages[ index ] = new UserProfilPage( index + 1 );
        QObject::connect( profilPages[ index ], SIGNAL( readyToPlay() ), this, SLOT( userReady() ) );
    }

    QObject::connect( &gamepadCom, SIGNAL( newMessageArrive( GamePadMsgType ) ), this, SLOT( newMessageArrive( GamePadMsgType ) ) );
    QObject::connect( &gameSelection, SIGNAL( startGame( const QString& ) ), this, SLOT( lauchGame( const QString& ) ) );
    QObject::connect( &gameSelection, SIGNAL( returnToProfileSelection() ), this, SLOT( showProfilSelectionView() ) );
    QObject::connect( &gameProcess, SIGNAL( gameStop( const QString& ) ), this, SLOT( gameStop( const QString& ) ) );


    this->views = new QStackedLayout();
    this->profilViewIndex = this->views->addWidget( this->prepareProfilPages() );
    this->gameSelectionViewIndex = this->views->addWidget( &this->gameSelection );

    QVBoxLayout* inGameLayout = new QVBoxLayout();
    inGameLayout->addWidget( new QLabel( "Un jeux est en cours..." ) );
    QWidget* inGameView = new QWidget();
    inGameView->setLayout( inGameLayout );
    this->gameIsRunningViewIndex = this->views->addWidget( inGameView );

    QWidget* pCentralWidget = new QWidget( this );
    pCentralWidget->setLayout( this->views );
    this->setCentralWidget( pCentralWidget );

    this->setWindowTitle( "Console de jeux" );
    this->installEventFilter( new CommandSimulator() );
}

QWidget* HomeWindow::prepareProfilPages()
{
    QWidget* pCentralWidget = new QWidget();
    QHBoxLayout* pHBox = new QHBoxLayout( pCentralWidget );

    pHBox->addWidget( profilPages[ 0 ] );
    pHBox->addWidget( profilPages[ 1 ] );
    pHBox->addWidget( profilPages[ 2 ] );
    pHBox->addWidget( profilPages[ 3 ] );
    pCentralWidget->setLayout( pHBox );

    return pCentralWidget;
}

HomeWindow::~HomeWindow()
{

}

void HomeWindow::newMessageArrive( GamePadMsgType message_ )
{
    int viewIndex = views->currentIndex();

    if( profilViewIndex == viewIndex )
    {
        size_t gamepadIndex = getGamepadIndex( message_ );
        profilPages[ gamepadIndex ]->process( message_ );
    }
    else if( gameSelectionViewIndex == viewIndex )
    {
        gameSelection.process( message_ );
    }
    else if( gameIsRunningViewIndex == viewIndex )
    {
        gameProcess.newMessageArrive( message_ );
    }
    else
    {
        qDebug() << "Unkown view " << viewIndex;
    }
}

void HomeWindow::userReady()
{
    bool atLeastOnePlayer = false;

    bool isEveryOneReady = std::all_of( profilPages, profilPages + MaxUser,
    [ &atLeastOnePlayer ]( UserProfilPage* userProfile )
    {
        atLeastOnePlayer = atLeastOnePlayer || userProfile->isActivated();
        return userProfile->isReady() || !userProfile->isActivated();
    });

    if( isEveryOneReady && atLeastOnePlayer )
    {
        this->views->setCurrentIndex( this->gameSelectionViewIndex );
    }
}

void  HomeWindow::showProfilSelectionView()
{
    this->views->setCurrentIndex( this->profilViewIndex );
}

bool HomeWindow::isOnProfilPage() const
{
    return this->views->currentIndex() == profilViewIndex;
}

bool HomeWindow::isOnGameSelectionPage() const
{
    return this->views->currentIndex() == gameSelectionViewIndex;
}

void HomeWindow::lauchGame( const QString& gamePath_ )
{
    gameProcess.startGame( gamePath_ );
    this->views->setCurrentIndex( gameIsRunningViewIndex );
}

void HomeWindow::gameStop( const QString& failueMessage_ )
{
    this->gameSelection.setFailureMessage( failueMessage_ );
    this->views->setCurrentIndex( gameSelectionViewIndex );
}


