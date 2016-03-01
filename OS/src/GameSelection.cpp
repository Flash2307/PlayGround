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

GameSelection::GameSelection()
{
    detectAvaibleGame();

    QHBoxLayout* pGameList = new QHBoxLayout();

    foreach( QString gameName, avaibleGames )
    {
        QLabel* pGameTitleLabel = new QLabel( gameName );
        QLabel* pGamePixmap = new QLabel();
        pGamePixmap->setPixmap( QPixmap( QString("%1/%2/%3").arg( gameBaseDir ).arg( gameName ).arg( gamePictureFileName ) ) );

        QLabel* pGameDescriptionLabel = new QLabel( readFiles( QStringList() << QString("%1/%2/%3").arg( gameBaseDir ).arg( gameName ).arg( gameDescriptionFileName ) ) );

        QPushButton* pStartGameBtn = new QPushButton( QString( "Débuter %1" ).arg( gameName )  );
        QObject::connect( pStartGameBtn, SIGNAL( clicked() ), this, SLOT( startGameRequest() ) );

        QVBoxLayout* gamePreview = new QVBoxLayout();
        gamePreview->addWidget( pGameTitleLabel );
        gamePreview->addWidget( pGamePixmap );
        gamePreview->addWidget( pGameDescriptionLabel );
        gamePreview->addWidget( pStartGameBtn );

        QWidget* gamePanel = new QWidget();
        gamePanel->setLayout( gamePreview );
        pGameList->addWidget( gamePanel );
    }

    this->setLayout( pGameList );

    QObject::connect( &currentGame, SIGNAL( finished(int, QProcess::ExitStatus) ), this, SLOT( gameFinished(int, QProcess::ExitStatus) ) );
    QObject::connect( &currentGame, SIGNAL( readyReadStandardError() ), this, SLOT( readyReadStandardError() ) );
    QObject::connect( &currentGame, SIGNAL( readyReadStandardOutput() ), this, SLOT( readyReadStandardOutput() ) );
    QObject::connect( &currentGame, SIGNAL( started() ), this, SLOT( started() ) );
}

void GameSelection::detectAvaibleGame()
{
    QDirIterator it( gameBaseDir );

    while( it.hasNext() )
    {
        QString gameName = it.fileName();

        if( it.fileInfo().isDir() && gameName != "." )
        {
            qDebug() << " Game avaible: " << gameName << '\n';
            avaibleGames.append( gameName );
        }

        it.next();
    }
}

void GameSelection::startGameRequest()
{

}

void GameSelection::gameFinished(int exitCode, QProcess::ExitStatus exitStatus)
{

}

void GameSelection::readyReadStandardError()
{

}

void GameSelection::readyReadStandardOutput()
{

}

void GameSelection::started()
{

}

