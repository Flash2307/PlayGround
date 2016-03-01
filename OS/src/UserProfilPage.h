#ifndef USERPROFILPAGE_H
#define USERPROFILPAGE_H

#include <cstddef>

#include "GamepadMsg.h"

class QWidget;
class QLabel;

class UserProfilPage
{
public:
    UserProfilPage( size_t gamepadIndex  );

    void process( GamePadMsgType message_ );
    bool isReady() const;
    QWidget* getWidget();
private:
    QWidget* pPage;
    QLabel* pUserNameLabel;
    bool activated;
    bool ready;
};

#endif // USERPROFILPAGE_H