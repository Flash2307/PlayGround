#include "GameSelection.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDirIterator>
#include <QScrollArea>
#include <QDebug>

#include "FileLoader.h"
#include "SelectableWidget.h"

constexpr char gameBaseDir[] = "./games";
constexpr char gamePictureFileName[] = "picture.jpg";
constexpr char gameDescriptionFileName[] = "description.txt";
constexpr char gameAppFileName[] = GAME_APP_EXE_NAME;
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

    pMainLayout = new QVBoxLayout(this);
    pFailureMessageLabel = new QLabel(this);
    pScrollArea = new QScrollArea(this);
    pGameListWidget = new QWidget(pScrollArea);
    pGameList = new QHBoxLayout(pScrollArea);

    foreach( Game game, avaibleGames )
    {
        SelectableWidget* gamePanel = new SelectableWidget( pScrollArea, game, LAUNCH );
        pGameList->addWidget( gamePanel );
        this->gamePanels.append( gamePanel );
    }

    pFailureMessageLabel->hide();

    pGameListWidget->setLayout( pGameList );

    pScrollArea->setWidget( pGameListWidget );

    pMainLayout->addWidget( pFailureMessageLabel );
    pMainLayout->addWidget( pScrollArea );

    setLayout( pMainLayout );
    setWidgetSelected( true );
}

void GameSelection::setWidgetSelected( bool selected_ )
{
    if( selectedGameIndex < (size_t)this->gamePanels.size() )
    {
        this->gamePanels[ selectedGameIndex ]->setSelected( selected_ );
        this->gamePanels[ selectedGameIndex ]->update();
    }
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
    int id = 0;
    while( it.hasNext() )
    {
        it.next();
        QString name = it.fileName();


        if( it.fileInfo().isDir() && name != "." && name != ".." )
        {
            qDebug() << "Game avaible: " << name;

            QString path = QString("%1/%2/%3").arg(gameBaseDir).arg(name).arg(gameAppFileName);

            avaibleGames.emplace_back(id++, name, path, fetchGameDescription(name) , QPixmap(fetchGameImage(name)));
        }
    }
}

void GameSelection::lauchGameCommand()
{
    GameConfig gameConfig;
    gameConfig.cmd = gamePanels.at(selectedGameIndex)->getGamePath();
    gameConfig.workingDir = ".";
    gameConfig.gameName = gamePanels.at(selectedGameIndex)->getGame().getName();

    qDebug() << "Start game " << gameConfig.cmd;

    emit startGame( gameConfig );
}

void GameSelection::process( GamePadMsgType message_ )
{
    if( isGamepadBBtn( message_ ) )
    {
        returnToProfileSelection();
    }
    else if( isGamepadABtn( message_ ) )
    {
        GameCommand command = gamePanels[ selectedGameIndex ]->getCommand();

        if(command == LAUNCH)
            lauchGameCommand();
        else if(command == SHOW_STATS)
        {
            emit showGameStatView( gamePanels[ selectedGameIndex ]->getGame().getName() );
        }
    }
    else if( this->gamePanels.size() > 0 )
    {
        if( isGamepadLeftArrow( message_ ) &&  selectedGameIndex > 0 )
        {
            setWidgetSelected( false );
            --selectedGameIndex;
            setWidgetSelected( true );
            this->update();
        }
        else if( isGamepadRigthArrow( message_ ) && selectedGameIndex + 1 < (size_t)this->gamePanels.size() )
        {
            setWidgetSelected( false );
            ++selectedGameIndex;
            setWidgetSelected( true );
            this->update();
        }
        else if( isGamepadUpArrow( message_ ) )
        {
            this->gamePanels[ selectedGameIndex ]->previousCommand();
        }
        else if( isGamepadDownArrow( message_ ) )
        {
            this->gamePanels[ selectedGameIndex ]->nextCommand();
        }
    }
}

