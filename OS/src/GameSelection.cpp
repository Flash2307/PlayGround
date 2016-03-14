#include "GameSelection.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDirIterator>
#include <QDebug>

#include "FileLoader.h"
#include "SelectableWidget.h"

constexpr char gameBaseDir[] = "./games";
constexpr char gamePictureFileName[] = "picture.jpg";
constexpr char gameDescriptionFileName[] = "description.txt";
constexpr char gameAppFileName[] = "game";
constexpr char selectedGameTagName[] = "elementWithFocus";
constexpr char defaultGameImg[] = "./img/NoImage.jpg";
constexpr char noDescriptionAvaibleText[] = "Aucune description du jeu disponible.";

static QString fetchGameImage( const QString& gameName_ )
{
    QString defaultPath = QString("%1/%2/%3").arg( gameBaseDir ).arg( gameName_ ).arg( gamePictureFileName );

    if( QFile::exists( defaultPath ) )
    {
        return defaultPath;
    }

    return QString( defaultGameImg );
}

static QString fetchGameDescription( const QString& gameName_ )
{
    QString defaultFilePath = QString("%1/%2/%3").arg( gameBaseDir ).arg( gameName_ ).arg( gameDescriptionFileName );

    if( QFile::exists( defaultFilePath ) )
    {
        return readFiles( QStringList() << defaultFilePath );
    }

    return QString( noDescriptionAvaibleText );
}

GameSelection::GameSelection() :
    selectedGameIndex( 0 )
{
    detectAvaibleGame();

    QHBoxLayout* pGameList = new QHBoxLayout();

    foreach( QString gameName, avaibleGames )
    {
        QLabel* pGameTitleLabel = new QLabel( gameName );
        pGameTitleLabel->setWordWrap( true );
        pGameTitleLabel->setFont( QFont( "Arial", 48, QFont::Bold ) );

        QLabel* pGamePixmap = new QLabel();
        pGamePixmap->setPixmap( QPixmap( fetchGameImage( gameName ) ).scaled( 400, 600 ) );
        pGamePixmap->setMaximumSize( QSize( 500, 800 ) );

        QLabel* pGameDescriptionLabel = new QLabel( fetchGameDescription( gameName ) );
        pGameDescriptionLabel->setWordWrap( true );
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

        SelectableWidget* gamePanel = new SelectableWidget();
        gamePanel->setMaximumWidth( 410 );
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
    this->setWidgetSelected( true );
}

void GameSelection::setWidgetSelected( bool selected_ )
{
    if( selectedGameIndex < (size_t)this->gamePanels.size() )
    {
        this->gamePanels[ selectedGameIndex ]->setSelected( selected_ );
        this->gamePanels[ selectedGameIndex ]->update();
    }
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
        QString gameCmd( "%1/%2/%3" );
        gameCmd = gameCmd.arg( gameBaseDir ).arg( pObj->objectName() ).arg( gameAppFileName );

        qDebug() << "Start game " << gameCmd;

        GameConfig gameConfig;
        gameConfig.cmd = gameCmd;
        gameConfig.workingDir = ".";

        emit startGame( gameConfig );
    }
}

void GameSelection::process( GamePadMsgType message_ )
{
    if( isGamepadBBtn( message_ ) )
    {
        this->pBackToProfileSelection->animateClick();
    }
    else if( isGamepadABtn( message_ ) )
    {
        QPushButton* pButton = this->gamePanels[ selectedGameIndex ]->findChild< QPushButton* >( avaibleGames[ selectedGameIndex ] );
         pButton->animateClick();
    }
    else if( this->gamePanels.size() > 0 )
    {
        if( isGamepadLeftArrow( message_ ) &&  selectedGameIndex > 0 )
        {
            setWidgetSelected( false );
            --selectedGameIndex;
            setWidgetSelected( true );
        }
        else if( isGamepadRigthArrow( message_ ) && selectedGameIndex + 1 < (size_t)this->gamePanels.size() )
        {
            setWidgetSelected( false );
            ++selectedGameIndex;
            setWidgetSelected( true );
        }
    }
}

