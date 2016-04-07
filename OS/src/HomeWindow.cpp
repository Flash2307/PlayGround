#include "HomeWindow.h"

#include <cassert>

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QStackedLayout>
#include <QVBoxLayout>

#include "CommandSimulator.h"
#include "GameProcess.h"
#include "Config.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow( parent ),
    gamepadCom( COM_PORT_NAME )
{
    for( size_t index = 0; index < MaxUser; ++index )
    {
        profilPages[ index ] = new UserProfilPage( index + 1 );
        QObject::connect( profilPages[ index ], SIGNAL( readyToPlay() ), this, SLOT( userReady() ) );
    }

    QObject::connect( &gamepadCom, SIGNAL( newMessageArrive( GamePadMsgType ) ), this, SLOT( newMessageArrive( GamePadMsgType ) ) );
    QObject::connect( &gameSelection, SIGNAL( startGame( GameConfig ) ), this, SLOT( lauchGame( GameConfig ) ) );
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
    this->setArrowKeyRepeat( false );
}

QWidget* HomeWindow::prepareProfilPages()
{
    QWidget* pCentralWidget = new QWidget();

    QVBoxLayout* pBox = new QVBoxLayout( pCentralWidget );
    pBox->addWidget( profilPages[ 0 ] );
    pBox->addWidget( profilPages[ 1 ] );
    pBox->addWidget( profilPages[ 2 ] );
    pBox->addWidget( profilPages[ 3 ] );
    pBox->setAlignment( Qt::AlignHCenter );
    pCentralWidget->setLayout( pBox );

    return pCentralWidget;
}

HomeWindow::~HomeWindow()
{

}

void HomeWindow::setArrowKeyRepeat( bool enable_ )
{
    this->arrowKeyRepeat = enable_;
}

void HomeWindow::updateGamepadMessage( GamePadMsgType& message_ )
{
    if( message_.acc.y > 400 )
    {
        setLeftArrow( message_, true );
    }
    else if( message_.acc.y < -400 )
    {
        setRigthArrow( message_, true );
    }

    if( message_.acc.x  > 400 )
    {
        setUpArrow( message_, true );
    }
    else if( message_.acc.x < -400 )
    {
        setDownArrow( message_, true );
    }

    size_t userIndex = getGamepadIndex( message_ );
    GamePadMsgType tmpMessage = message_;
    setABtn( tmpMessage, isGamepadABtn( message_  ) && !isGamepadABtn( lastMessage[ userIndex ] ) );
    setBBtn( tmpMessage, isGamepadBBtn( message_  ) && !isGamepadBBtn( lastMessage[ userIndex ] ) );

    if( !this->arrowKeyRepeat )
    {
        setUpArrow( tmpMessage, isGamepadUpArrow( message_  ) && !isGamepadUpArrow( lastMessage[ userIndex ] ) );
        setDownArrow( tmpMessage, isGamepadDownArrow( message_  ) && !isGamepadDownArrow( lastMessage[ userIndex ] ) );
        setLeftArrow( tmpMessage, isGamepadLeftArrow( message_  ) && !isGamepadLeftArrow( lastMessage[ userIndex ] ) );
        setRigthArrow( tmpMessage, isGamepadRigthArrow( message_  ) && !isGamepadRigthArrow( lastMessage[ userIndex ] ) );
    }

    lastMessage[ userIndex ] = message_;
    message_ = tmpMessage;
}

void HomeWindow::newMessageArrive( GamePadMsgType message_ )
{
    int viewIndex = views->currentIndex();

    qDebug() << "acc.x: " << message_.acc.x;
    qDebug() << "acc.y: " << message_.acc.y;
    qDebug() << "acc.z: " << message_.acc.z;
    qDebug() << "acc.other: " << message_.acc.other;

    ON_USE_GAMEPAD( updateGamepadMessage( message_ ); )

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
    bool isEveryOneReady = false;
    for(UserProfilPage* item : profilPages)
    {
        if(item->isConnected())
            isEveryOneReady = true;
        else if(item->isConnecting())
        {
            isEveryOneReady = false;
            break;
        }
    }

    if( isEveryOneReady )
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

void HomeWindow::lauchGame( GameConfig gameConfig_ )
{
    for( size_t index = 0; index < MaxUser; ++index )
    {
        if( profilPages[ index ]->isConnected() )
        {
            assert( profilPages[ index ] != nullptr );
            gameConfig_.playerNames[ index ] = profilPages[ index ]->getUsername();
        }
    }

    gameProcess.startGame( gameConfig_ );
    this->views->setCurrentIndex( gameIsRunningViewIndex );
    this->setArrowKeyRepeat( true );
    this->hide();
}

void HomeWindow::gameStop( const QString& failueMessage_ )
{
    this->gameSelection.setFailureMessage( failueMessage_ );
    this->views->setCurrentIndex( gameSelectionViewIndex );
    this->setArrowKeyRepeat( false );
    this->show();
}


