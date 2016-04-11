#include "UserProfilPage.h"

#include <QtCore>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>

#include "FileLoader.h"

constexpr static size_t MaxUserProfilWidth = 500;

void applyTexture( QWidget* pWidget, const QString& texturePath )
{
    QPalette p;
    QPixmap bg( texturePath );
    p.setBrush(QPalette::Background, bg);
    pWidget->setAutoFillBackground(true);
    pWidget->setPalette(p);
}

UserProfilPage::UserProfilPage( size_t ) :
    selectedProfileIndex(0)
{
    //TODO : get this from the database
    profiles.emplace_back(0, "Kevin", QPixmap("img/NoImage.jpg"));
    profiles.emplace_back(1, "Antoine", QPixmap("img/NoImage.jpg"));
    profiles.emplace_back(2, "Gabriel", QPixmap("img/NoImage.jpg"));
    profiles.emplace_back(3, "Joel", QPixmap("img/NoImage.jpg"));
    profiles.emplace_back(4, "Benjamin", QPixmap("img/NoImage.jpg"));

    this->setStyleSheet( readFiles( QStringList() << "css/GameProfil.css" ) );
    applyTexture( this, "./img/ProfilPage.jpg" );

    //----- Panels -----
    layoutGlobal = new QVBoxLayout(this);
    this->setLayout(layoutGlobal);
    layoutGlobal->setAlignment( Qt::AlignTop );

    panelNotConnected = new QWidget(this);
    layoutGlobal->addWidget(panelNotConnected);

    panelConnecting = new QWidget(this);
    layoutGlobal->addWidget(panelConnecting);

    panelConnected = new QWidget(this);
    layoutGlobal->addWidget(panelConnected);

    //----- Not connected -----
    layoutNotConnected = new QVBoxLayout(panelNotConnected);
    layoutNotConnected->setAlignment(Qt::AlignCenter);
    panelNotConnected->setLayout(layoutNotConnected);

    labelNotConnectedInstruction = new QLabel("Appuyer sur A pour vous connecter", panelNotConnected);
    layoutNotConnected->addWidget(labelNotConnectedInstruction);

    //----- Connecting -----
    layoutConnecting = new QVBoxLayout(panelConnecting);
    layoutConnecting->setAlignment(Qt::AlignCenter);
    panelConnecting->setLayout(layoutConnecting);

    imageConnectingArrowUp = new QLabel(panelConnecting);
    imageConnectingArrowUp->setPixmap(QPixmap("img/ArrowUp.png"));
    imageConnectingArrowUp->setFixedSize(90, 25);
    imageConnectingArrowUp->setScaledContents(true);
    layoutConnecting->addWidget(imageConnectingArrowUp);

    // Profile
    widgetConnectingProfile = new QWidget(panelConnecting);
    layoutConnecting->addWidget(widgetConnectingProfile);
    layoutConnecting->setAlignment(Qt::AlignCenter);

    layoutConnectingProfile = new QHBoxLayout(widgetConnectingProfile);
    widgetConnectingProfile->setLayout(layoutConnectingProfile);

    imageConnectingProfilePict = new QLabel(widgetConnectingProfile);
    imageConnectingProfilePict->setFixedSize(75, 75);
    imageConnectingProfilePict->setScaledContents(true);
    layoutConnectingProfile->addWidget(imageConnectingProfilePict);
    labelConnectingProfileName = new QLabel(widgetConnectingProfile);
    layoutConnectingProfile->addWidget(labelConnectingProfileName);


    imageConnectingArrowDown = new QLabel(panelConnecting);
    imageConnectingArrowDown->setPixmap(QPixmap("img/ArrowDown.png"));
    imageConnectingArrowDown->setFixedSize(90, 25);
    imageConnectingArrowDown->setScaledContents(true);
    layoutConnecting->addWidget(imageConnectingArrowDown);

    labelConnectingControls = new QLabel("A : Sélectionner       B : Annuler", panelConnecting);
    layoutConnecting->addWidget(labelConnectingControls);

    //----- Connected ------
    layoutConnectedProfile = new QHBoxLayout(panelConnected);
    layoutConnectedProfile->setAlignment(Qt::AlignCenter);
    panelConnected->setLayout(layoutConnectedProfile);

    imageConnectedProfilePict = new QLabel(panelConnected);
    imageConnectedProfilePict->setFixedSize(75, 75);
    imageConnectedProfilePict->setScaledContents(true);
    layoutConnectedProfile->addWidget(imageConnectedProfilePict);
    labelConnectedProfileName = new QLabel(panelConnected);
    layoutConnectedProfile->addWidget(labelConnectedProfileName);

    labelConnectedReady = new QLabel(" - Prêt !", panelConnected);
    layoutConnectedProfile->addWidget(labelConnectedReady);

    changeState(NOT_CONNECTED);
    changeSelectedProfile(selectedProfileIndex);
}


void UserProfilPage::changeState(State newState)
{
    state = newState;
    panelNotConnected->setVisible(state == NOT_CONNECTED);
    panelConnecting->setVisible(state == CONNECTING);
    panelConnected->setVisible(state == CONNECTED);
}

void UserProfilPage::changeSelectedProfile(int index)
{
    if((size_t)index >= profiles.size() || index < 0)
        return;

    selectedProfileIndex = index;

    Profile& p = profiles.at(index);

    imageConnectingProfilePict->setPixmap(p.getPicture());
    labelConnectingProfileName->setText(p.getName());

    imageConnectedProfilePict->setPixmap(p.getPicture());
    labelConnectedProfileName->setText(p.getName());
}


void UserProfilPage::process( GamePadMsgType message_ )
{
    if( isGamepadABtn( message_ ) )
    {
        if(state != CONNECTED )
            changeState((State)(state + 1));
        else
            emit readyToPlay();
    }
    else if( isGamepadUpArrow( message_ ) && state == CONNECTING )
    {
        changeSelectedProfile(selectedProfileIndex - 1);
    }
    else if( isGamepadDownArrow( message_ )  && state == CONNECTING )
    {
        changeSelectedProfile(selectedProfileIndex + 1);
    }
    else if( isGamepadBBtn( message_ ) && state != NOT_CONNECTED )
    {
        changeState((State)(state - 1));
    }
}

void UserProfilPage::sendGameStatistic( const GameStatistic& statistic_ )
{
    qDebug() << "Send statistic for game " << statistic_.gameName;
}

