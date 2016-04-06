#include "GameProcess.h"

#include <QDebug>

constexpr char logFilePath[] = "./games/log.txt";

GameProcess::GameProcess() :
    processStdin( &currentGame ),
    lastState( QProcess::NotRunning )
{
    QObject::connect( &currentGame, SIGNAL( finished(int, QProcess::ExitStatus) ), this, SLOT( gameFinished(int, QProcess::ExitStatus) ) );
    QObject::connect( &currentGame, SIGNAL( readyReadStandardError() ), this, SLOT( readyReadStandardError() ) );
    QObject::connect( &currentGame, SIGNAL( readyReadStandardOutput() ), this, SLOT( readyReadStandardOutput() ) );
    QObject::connect( &currentGame, SIGNAL( stateChanged(QProcess::ProcessState) ), this, SLOT( stateChanged(QProcess::ProcessState) ) );
}

GameProcess::~GameProcess()
{
    this->currentGame.terminate();
}

void GameProcess::newMessageArrive( GamePadMsgType message_ )
{
    if( currentGame.state() == QProcess::Running )
    {
        qDebug() << "Send message: " << message_.cmd;
        processStdin << message_.cmd << ' ';
        processStdin.flush();
    }
}

void GameProcess::stateChanged(QProcess::ProcessState newState)
{
    if( ( newState == QProcess::NotRunning && lastState == QProcess::Starting ) ||
        ( newState == QProcess::NotRunning && lastState == QProcess::NotRunning )
    )
    {
        emit gameStop( QString( "Le jeux n'a pas pu être démarré." ) );
    }

    lastState = newState;
}

void GameProcess::gameFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    QString failureMessage;

    if( exitStatus == QProcess::CrashExit || exitCode != 0 )
    {
        failureMessage = "Le jeux c'est terminé de manière inatandu.";
    }

    emit gameStop( failureMessage );
}

void GameProcess::readyReadStandardError()
{
    qDebug() << this->currentGame.readAllStandardError();
}

void GameProcess::readyReadStandardOutput()
{
    // Command from the game arrive, answer on game stdin
}

void GameProcess::startGame( GameConfig gameConfig_ )
{
    gameConfig = gameConfig_;

    QStringList arguments;

    for( size_t index = 0; index < MaxUser; ++index )
    {
        QString playerName = gameConfig.playerNames[ index ];

        if( !playerName.isEmpty() )
        {
            arguments.push_back( QString("%1 %2").arg( playerName ).arg( index ) );
        }
    }

    currentGame.setWorkingDirectory( gameConfig_.workingDir );
    currentGame.start( gameConfig_.cmd, arguments );
    processStdin.setDevice( &currentGame );
}
