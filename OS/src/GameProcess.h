#ifndef GAMEPROCESS_H
#define GAMEPROCESS_H

#include <QObject>
#include <QProcess>

#include "GamepadMsg.h"

class GameProcess : public QObject
{
    Q_OBJECT
public:
    GameProcess();
public slots:
    void stateChanged(QProcess::ProcessState newState);
    void gameFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();

    void newMessageArrive( GamePadMsgType message_ );
    void startGame( const QString& path_ );
signals:
    void gameStop( const QString& failureMessage_ );
private:
    QProcess currentGame;
    QTextStream processStdin;
    QProcess::ProcessState lastState;
};

#endif // GAMEPROCESS_H
