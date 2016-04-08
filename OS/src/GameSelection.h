#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QWidget>
#include <QProcess>

#include "GamepadMsg.h"
#include "GameProcess.h"
#include "Game.h"

class QLabel;
class QPushButton;
class SelectableWidget;

class GameSelection : public QWidget
{
    Q_OBJECT
public:
    GameSelection();
    void setFailureMessage( const QString& failueMessage_ );

public slots:
    void detectAvaibleGame();
    void lauchGameCommand();
    void process( GamePadMsgType message_ );
    void setWidgetSelected( bool selected_ );

signals:
    void startGame( GameConfig gameConfig_ );
    void returnToProfileSelection();

private:
    void prepareFailureMessageLabel();

    QLabel* pFailureMessageLabel;

    std::vector< Game > avaibleGames;    // Games base dir.
    QVector< SelectableWidget* > gamePanels;
    size_t selectedGameIndex;
};

#endif // GAMESELECTION_H
