#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QProcess>

struct GameLaucher
{
    QString gamePath;
    QString gamePicturePath;
    QString gameDescription;
};

class GameSelection : public QObject
{
    Q_OBJECT
public:
    GameSelection();

    QWidget* getView();
public slots:
    void gameFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();
private:
    QGraphicsScene scene;
    QGraphicsView view;
    QProcess currentGame;
    QVector< GameLaucher > avaibleGames;
};

#endif // GAMESELECTION_H
