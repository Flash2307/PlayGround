#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include "GamePadCom.h"
#include "UserProfilPage.h"
#include "GameSelection.h"
#include "GameProcess.h"
#include "DatabaseFacade.h"

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
    void setArrowKeyRepeat( bool enable_ );
public slots:
    void lauchGame( GameConfig gameConfig_ );
    void gameStop( const QString& failueMessage_ );
    void newMessageArrive( GamePadMsgType );
    void userReady();
    void showProfilSelectionView();
    void saveScores( const std::vector< UserScore >& scores_ );
private:
    QWidget* prepareProfilPages();
    void updateGamepadMessage( GamePadMsgType& message_ );

    DatabaseFacade db;

    GamePadCom gamepadCom;
    GameSelection gameSelection;
    GameProcess gameProcess;
    UserProfilPage* profilPages[ MaxUser ];

    QStackedLayout* views;
    int profilViewIndex;
    int gameSelectionViewIndex;
    int gameIsRunningViewIndex;
    GamePadMsgType lastMessage[ MaxUser ];
    bool arrowKeyRepeat = false;
};

#endif // HOMEWINDOW_H
