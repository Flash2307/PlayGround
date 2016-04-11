#ifndef GAMEPROCESS_H
#define GAMEPROCESS_H

#include <QObject>
#include <QProcess>
#include <QUdpSocket>
#include <QFile>

#include "GamepadMsg.h"

struct GameConfig
{
    QString cmd;
    QString workingDir;
    QString playerNames[ MaxUser ];
};

class GameProcess : public QObject
{
    Q_OBJECT
public:
    GameProcess();
    ~GameProcess();
public slots:
    void stateChanged(QProcess::ProcessState newState);
    void gameFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();

    void newMessageArrive( GamePadMsgType message_ );
    void startGame( GameConfig gameConfig_ );
signals:
    void gameStop( const QString& failureMessage_ );
private:
    QProcess currentGame;
    QProcess::ProcessState lastState;
    QUdpSocket comWithGame;
    GameConfig gameConfig;
};

#endif // GAMEPROCESS_H
