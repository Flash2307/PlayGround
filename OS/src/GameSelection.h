#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QWidget>
#include <QProcess>

class GameSelection : public QWidget
{
    Q_OBJECT
public:
    GameSelection();
public slots:
    void gameFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();
    void detectAvaibleGame();

    void startGameRequest();
private:
    QProcess currentGame;
    QVector< QString > avaibleGames;    // Games base dir.
};

#endif // GAMESELECTION_H
