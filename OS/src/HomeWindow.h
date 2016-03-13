#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include "GamePadCom.h"
#include "UserProfilPage.h"
#include "GameSelection.h"
#include "GameProcess.h"

class QLabel;
class QStackedLayout;

class HomeWindow : public QMainWindow
{
    Q_OBJECT
public:
    HomeWindow(QWidget *parent = 0);
    ~HomeWindow();

    bool isOnProfilPage() const;
    bool isOnGameSelectionPage() const;
public slots:
    void lauchGame( GameConfig gameConfig_ );
    void gameStop( const QString& failueMessage_ );
    void newMessageArrive( GamePadMsgType );
    void userReady();
    void showProfilSelectionView();
private:
    QWidget* prepareProfilPages();

    GamePadCom gamepadCom;
    GameSelection gameSelection;
    GameProcess gameProcess;
    UserProfilPage* profilPages[ MaxUser ];

    QStackedLayout* views;
    int profilViewIndex;
    int gameSelectionViewIndex;
    int gameIsRunningViewIndex;
};

#endif // HOMEWINDOW_H
