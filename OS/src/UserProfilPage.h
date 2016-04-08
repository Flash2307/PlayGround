#ifndef USERPROFILPAGE_H
#define USERPROFILPAGE_H

#include <QString>
#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <cstddef>

#include "GamepadMsg.h"
#include "Profile.h"

class QWidget;
class QLabel;
class QPushButton;
class QLineEdit;
class QString;

enum State
{
    NOT_CONNECTED,
    CONNECTING,
    CONNECTED
};

struct GameStatistic
{
    size_t score;
    QString gameName;
};

class UserProfilPage : public QWidget
{
    Q_OBJECT
public:
    UserProfilPage( size_t gamepadIndex  );

    void process( GamePadMsgType message_ );

    inline QString getUsername() const {return profiles.at(selectedProfileIndex).getName();}
    inline Profile getSelectedProfile() const {return profiles.at(selectedProfileIndex);}

    inline bool isConnected() const {return state == CONNECTED;}
    inline bool isConnecting() const {return state == CONNECTING;}

    void sendGameStatistic( const GameStatistic& statistic_ );

signals:
    void readyToPlay();

private:
    void changeState(State newState);
    void changeSelectedProfile(int index);

private:
    int selectedProfileIndex = 0;
    State state = NOT_CONNECTED;
    std::vector<Profile> profiles;

    // UI
    QVBoxLayout* layoutGlobal = nullptr;
    QWidget* panelNotConnected = nullptr;
    QWidget* panelConnecting = nullptr;
    QWidget* panelConnected = nullptr;

    QVBoxLayout* layoutNotConnected = nullptr;
    QLabel* labelNotConnectedInstruction = nullptr;

    QVBoxLayout* layoutConnecting = nullptr;
    QLabel* imageConnectingArrowUp = nullptr;
    QWidget* widgetConnectingProfile = nullptr;
    QHBoxLayout* layoutConnectingProfile = nullptr;
    QLabel* imageConnectingProfilePict = nullptr;
    QLabel* labelConnectingProfileName = nullptr;
    QLabel* imageConnectingArrowDown = nullptr;
    QLabel* labelConnectingControls = nullptr;

    QHBoxLayout* layoutConnectedProfile = nullptr;
    QLabel* imageConnectedProfilePict = nullptr;
    QLabel* labelConnectedProfileName = nullptr;
    QLabel* labelConnectedReady = nullptr;
};

#endif // USERPROFILPAGE_H
