#include "UserProfilPage.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPalette>

void applyTexture( QWidget* pWidget, const QString& texturePath )
{
    QPalette p;
    QPixmap bg( texturePath );
    p.setBrush(QPalette::Background, bg);
    pWidget->setAutoFillBackground(true);
    pWidget->setPalette(p);
}

UserProfilPage::UserProfilPage( size_t gamepadIndex ) :
    pPage( nullptr ),
    pUserNameLabel( nullptr ),
    unactivatedMessage( "Manette " + QString().setNum( gamepadIndex ) + " non activé"  ),
    activated( false ),
    ready( false )
{
    QVBoxLayout* pVBox = new QVBoxLayout();

    pPage = new QWidget();
    applyTexture( pPage, "./img/ProfilPage.jpg" );
    pUserNameLabel = new QLabel( unactivatedMessage );
    pVBox->addWidget( pUserNameLabel );
    pVBox->setAlignment( Qt::AlignTop );
    pPage->setLayout( pVBox );
}

void UserProfilPage::process( GamePadMsgType message_ )
{
    activated = !isGamepadShutdown( message_ );

    if( activated )
    {

    }
    else
    {
        pUserNameLabel->setText( unactivatedMessage );
    }
}

bool UserProfilPage::isReady() const
{
    return this->ready || !this->activated;
}

QWidget* UserProfilPage::getWidget()
{
    return this->pPage;
}
