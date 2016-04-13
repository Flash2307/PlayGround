#ifndef GAMESTATPANEL_H
#define GAMESTATPANEL_H

#include <vector>

#include <QWidget>

#include "Score.h"
#include "GamepadMsg.h"

class QLabel;
class QPushButton;
struct Score;

class GameStatPanel : public QWidget
{
    Q_OBJECT
public:
    explicit GameStatPanel(QWidget *parent = 0);
    void showStatForGame( const QString& gameName_, const std::vector< Score >& highScores_ );
    void process( GamePadMsgType gamepadMsg_ );
signals:
    void goBackToGameSelection();
public slots:
private:
    QPushButton* returnToGameSelection = nullptr;
    QLabel* pScoreLbl = nullptr;
};

#endif // GAMESTATPANEL_H
