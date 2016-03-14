#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QWidget>
#include <QProcess>

#include "GamepadMsg.h"
#include "GameProcess.h"

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
    void startGameRequest();
    void process( GamePadMsgType message_ );
    void setWidgetSelected( bool selected_ );
signals:
    void startGame( GameConfig gameConfig_ );
    void returnToProfileSelection();
private:
    void prepareFailureMessageLabel();
    void prepareBackToSelectionProfileBtn();

    QLabel* pFailureMessageLabel;
    QPushButton* pBackToProfileSelection;

    QVector< QString > avaibleGames;    // Games base dir.
    QVector< SelectableWidget* > gamePanels;
    size_t selectedGameIndex;
};

#endif // GAMESELECTION_H
