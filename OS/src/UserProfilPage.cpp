#include "UserProfilPage.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

UserProfilPage::UserProfilPage( size_t gamepadIndex ) :
    pPage( nullptr ),
    pUserNameLabel( nullptr ),
    activated( false ),
    ready( false )
{
    QVBoxLayout* pVBox = new QVBoxLayout();

    pPage = new QWidget();
    pUserNameLabel = new QLabel( "Manette " + QString().setNum( gamepadIndex ) + "Non activé" );

    pVBox->addWidget( pUserNameLabel );
    pPage->setLayout( pVBox );
}

void UserProfilPage::process( GamePadMsgType message_ )
{

}

bool UserProfilPage::isReady() const
{
    return this->ready;
}

QWidget* UserProfilPage::getWidget()
{
    return this->pPage;
}
