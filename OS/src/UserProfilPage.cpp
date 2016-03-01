#include "UserProfilPage.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>

#include "FileLoader.h"

void applyTexture( QWidget* pWidget, const QString& texturePath )
{
    QPalette p;
    QPixmap bg( texturePath );
    p.setBrush(QPalette::Background, bg);
    pWidget->setAutoFillBackground(true);
    pWidget->setPalette(p);
}

UserProfilPage::UserProfilPage( size_t gamepadIndex ) :
    pUserNameLabel( nullptr ),
    unactivatedMessage( "Manette " + QString().setNum( gamepadIndex ) + " non activé"  ),
    activated( false ),
    ready( false )
{
    pUserNameLabel = new QLabel( unactivatedMessage );

    pConnectToProfilBtn = new QPushButton( "Connexion" );
    pConnectToProfilBtn->hide();
    QObject::connect( pConnectToProfilBtn, SIGNAL( clicked() ), this, SLOT( userConnect() ) );

    pUserNameEditor = new QLineEdit();
    pUserNameEditor->hide();

    QVBoxLayout* pVBox = new QVBoxLayout();
    pVBox->addWidget( pUserNameLabel );
    pVBox->addWidget( pUserNameEditor );
    pVBox->addWidget( pConnectToProfilBtn );
    pVBox->setAlignment( Qt::AlignTop );

    this->setLayout( pVBox );
    this->setStyleSheet( readFiles( QStringList() << "css/GameProfil.css" ) );
    applyTexture( this, "./img/ProfilPage.jpg" );
}

void UserProfilPage::process( GamePadMsgType message_ )
{
    activated = !isGamepadShutdown( message_ );

    if( activated )
    {
        if( isGamepadABtn( message_ ) )
        {
            qDebug() << "Db call to connextuser";
            qDebug() << "Show user statistic?";
            pConnectToProfilBtn->animateClick();
        }
        else
        {
            pUserNameLabel->setText( "Entrer votre nom d'utilisateur:" );
            pUserNameEditor->clear();
            pUserNameEditor->show();
            pConnectToProfilBtn->show();
        }
    }
    else
    {
        pUserNameLabel->setText( unactivatedMessage );
        pUserNameEditor->hide();
        pConnectToProfilBtn->hide();
    }
}

void UserProfilPage::userConnect()
{
    this->ready = true;
    emit readyToPlay();
}

bool UserProfilPage::isReady() const
{
    return this->ready;
}

bool UserProfilPage::isActivated() const
{
    return this->activated;
}

