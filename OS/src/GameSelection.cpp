#include "GameSelection.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDirIterator>
#include <QDebug>

#include "FileLoader.h"

constexpr char gameBaseDir[] = "./games";
constexpr char gamePictureFileName[] = "picture.jpg";
constexpr char gameDescriptionFileName[] = "description.txt";
constexpr char gameAppFileName[] = "game";
constexpr char selectedGameTagName[] = "elementWithFocus";

GameSelection::GameSelection() :
    selectedGameIndex( 0 )
{
    detectAvaibleGame();

    QHBoxLayout* pGameList = new QHBoxLayout();

    foreach( QString gameName, avaibleGames )
    {
        QLabel* pGameTitleLabel = new QLabel( gameName );
        pGameTitleLabel->setFont( QFont( "Arial", 48, QFont::Bold ) );

        QLabel* pGamePixmap = new QLabel();
        pGamePixmap->setPixmap( QPixmap( QString("%1/%2/%3").arg( gameBaseDir ).arg( gameName ).arg( gamePictureFileName ) ).scaled( 400, 600 ) );
        pGamePixmap->setMaximumSize( QSize( 500, 800 ) );

        QLabel* pGameDescriptionLabel = new QLabel( readFiles( QStringList() << QString("%1/%2/%3").arg( gameBaseDir ).arg( gameName ).arg( gameDescriptionFileName ) ) );
        pGameDescriptionLabel->setFont( QFont( "Arial", 34 ) );

        QPushButton* pStartGameBtn = new QPushButton( QString( "Débuter %1" ).arg( gameName )  );
        pStartGameBtn->setObjectName( gameName );
        pStartGameBtn->setMaximumWidth( 400 );
        QObject::connect( pStartGameBtn, SIGNAL( clicked() ), this, SLOT( startGameRequest() ) );

        QVBoxLayout* gamePreview = new QVBoxLayout();
        gamePreview->addWidget( pGameTitleLabel );
        gamePreview->addWidget( pGamePixmap );
        gamePreview->addWidget( pGameDescriptionLabel );
        gamePreview->addStretch();
        gamePreview->addWidget( pStartGameBtn );

        QWidget* gamePanel = new QWidget();
        gamePanel->setLayout( gamePreview );
        pGameList->addWidget( gamePanel );
        this->gamePanels.append( gamePanel );
    }

    this->prepareBackToSelectionProfileBtn();
    this->prepareFailureMessageLabel();

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    pMainLayout->addWidget( this->pFailureMessageLabel );
    pMainLayout->addLayout( pGameList );
    pMainLayout->addWidget( this->pBackToProfileSelection );

    this->setLayout( pMainLayout );
    this->setObjectName( "mainPane" );
    this->setStyleSheet( readFiles( QStringList() << "css/GameSelection.css" ) );
}

void GameSelection::prepareFailureMessageLabel()
{
    this->pFailureMessageLabel = new QLabel();
    this->pFailureMessageLabel->hide();
}

void GameSelection::prepareBackToSelectionProfileBtn()
{
    this->pBackToProfileSelection = new QPushButton( "Back" );
    QObject::connect( this->pBackToProfileSelection, SIGNAL( clicked() ), this, SIGNAL( returnToProfileSelection() ) );
}

void GameSelection::setFailureMessage( const QString& failueMessage_ )
{
    if( failueMessage_.isEmpty() )
    {
        this->pFailureMessageLabel->setText( QString() );
        this->pFailureMessageLabel->hide();
    }
    else
    {
        this->pFailureMessageLabel->setText( failueMessage_ );
        this->pFailureMessageLabel->show();
    }
}

void GameSelection::detectAvaibleGame()
{
    QDirIterator it( gameBaseDir );

    while( it.hasNext() )
    {
        QString gameName = it.fileName();

        if( it.fileInfo().isDir() && gameName != "." )
        {
            qDebug() << "Game avaible: " << gameName;
            avaibleGames.append( gameName );
        }

        it.next();
    }
}

void GameSelection::startGameRequest()
{
    QObject* pObj = sender();

    if( pObj != nullptr && pObj->objectName().isEmpty() == false )
    {
        QString gameAppPath("%1/%2/%3");
        gameAppPath = gameAppPath.arg( gameBaseDir ).arg( pObj->objectName() ).arg( gameAppFileName );

        qDebug() << "Start game " << gameAppPath;
        emit startGame( gameAppPath );
    }
}

void GameSelection::process( GamePadMsgType message_ )
{
    if( isGamepadBBtn( message_ ) )
    {

    }
    if( this->gamePanels.size() > 0 )
    {

    }
}

