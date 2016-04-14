#ifndef GAMESTATPANEL_H
#define GAMESTATPANEL_H

#include <vector>

#include <QWidget>
#include <QVBoxLayout>

#include "Score.h"
#include "GamepadMsg.h"
#include "DatabaseFacade.h"
#include "HighScoreLine.h"

class QLabel;
class QPushButton;
struct Score;

class GameStatPanel : public QWidget
{
    Q_OBJECT
public:
    explicit GameStatPanel(QWidget *parent);
    void showStatForGame(const QString& gameName_);
    void process( GamePadMsgType gamepadMsg_ );
signals:
    void goBackToGameSelection();
public slots:
private:
    DatabaseFacade db;

    QVBoxLayout* scoreAndButtonLayout = nullptr;
    QLabel* labelGameName = nullptr;
    std::vector<HighScoreLine*> scoreLines;
};

#endif // GAMESTATPANEL_H
