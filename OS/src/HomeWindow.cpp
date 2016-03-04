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

    this->views = new QStackedLayout();
    this->profilViewIndex = this->views->addWidget( this->prepareProfilPages() );
    this->gameSelectionViewIndex = this->views->addWidget( &this->gameSelection );

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
    size_t gamepadIndex = getGamepadIndex( message_ );
    profilPages[ gamepadIndex ]->process( message_ );
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

bool HomeWindow::isOnProfilPage() const
{
    return this->views->currentIndex() == profilViewIndex;
}

bool HomeWindow::isOnGameSelectionPage() const
{
    return this->views->currentIndex() == gameSelectionViewIndex;
}

