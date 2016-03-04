#ifndef USERPROFILPAGE_H
#define USERPROFILPAGE_H

#include <QString>
#include <QWidget>

#include <cstddef>

#include "GamepadMsg.h"

class QWidget;
class QLabel;
class QPushButton;
class QLineEdit;

class UserProfilPage : public QWidget
{
    Q_OBJECT
public:
    UserProfilPage( size_t gamepadIndex  );

    void process( GamePadMsgType message_ );
    bool isReady() const;
    bool isActivated() const;
public slots:
    void userConnect();
signals:
    void readyToPlay();
private:
    void updateUsenameText( bool increment );

    QLabel* pUserNameLabel;
    QLineEdit* pUserNameEditor;
    QPushButton* pConnectToProfilBtn;
    QString unactivatedMessage;
    bool activated;
    bool ready;
};

#endif // USERPROFILPAGE_H
