#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QWidget>
#include <QProcess>

#include "GamepadMsg.h"

class GameProcess : public QObject
{
    Q_OBJECT
public:
    GameProcess();
public slots:
    void gameFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();

    void startGame( const QString& path_ );
private:
    QProcess currentGame;
};

class GameSelection : public QWidget
{
    Q_OBJECT
public:
    GameSelection();
public slots:
    void detectAvaibleGame();
    void startGameRequest();
    void process( GamePadMsgType message_ );
signals:
    void startGame( const QString& path_ );
private:
    QVector< QString > avaibleGames;    // Games base dir.
    QVector< QWidget* > gamePanels;
    size_t selectedGameIndex;
};

#endif // GAMESELECTION_H
