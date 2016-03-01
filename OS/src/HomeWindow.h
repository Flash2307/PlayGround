#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include "GamePadCom.h"
#include "UserProfilPage.h"
#include "GameSelection.h"

class QLabel;
class QStackedLayout;

class HomeWindow : public QMainWindow
{
    Q_OBJECT
public:
    constexpr static size_t MaxUser = 4;

    HomeWindow(QWidget *parent = 0);
    ~HomeWindow();

    bool isOnProfilPage() const;
    bool isOnGameSelectionPage() const;
public slots:
    void newMessageArrive( GamePadMsgType );
    void userReady();
private:
    QWidget* prepareProfilPages();

    GamePadCom gamepadCom;
    GameSelection gameSelection;
    UserProfilPage* profilPages[ MaxUser ];

    QStackedLayout* views;
    int profilViewIndex;
    int gameSelectionViewIndex;
};

#endif // HOMEWINDOW_H
