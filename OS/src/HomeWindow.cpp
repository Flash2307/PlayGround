#include "HomeWindow.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QStackedLayout>

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow( parent ),
    profilPages( { UserProfilPage( 1 ), UserProfilPage( 2 ), UserProfilPage( 3 ), UserProfilPage( 4 ) } )
{
    QObject::connect( &gamepadCom, SIGNAL( newMessageArrive( GamePadMsgType ) ), this, SLOT( newMessageArrive( GamePadMsgType ) ) );

    this->views = new QStackedLayout();
    this->profilViewIndex = this->views->addWidget( this->prepareProfilPages() );
    this->gameSelectionViewIndex = this->views->addWidget( this->gameSelection.getView() );

    QWidget* pCentralWidget = new QWidget( this );
    pCentralWidget->setLayout( this->views );
    this->setCentralWidget( pCentralWidget );
}

QWidget* HomeWindow::prepareProfilPages()
{
    QWidget* pCentralWidget = new QWidget();
    QGridLayout* pGrid = new QGridLayout( pCentralWidget );

    pGrid->addWidget( profilPages[ 0 ].getWidget(), 0, 0, 1 , 3 );
    pGrid->addWidget( profilPages[ 1 ].getWidget(), 0, 1, 1 , 3 );
    pGrid->addWidget( profilPages[ 2 ].getWidget(), 0, 2, 1 , 3 );
    pGrid->addWidget( profilPages[ 3 ].getWidget(), 0, 3, 1 , 3 );
    pCentralWidget->setLayout( pGrid );

    return pCentralWidget;
}

HomeWindow::~HomeWindow()
{

}

void HomeWindow::newMessageArrive( GamePadMsgType message_ )
{
    size_t gamepadIndex = getGamepadIndex( message_ );
    profilPages[ gamepadIndex ].process( message_ );

    bool isEveryOneReady = std::all_of( profilPages, profilPages + MaxUser,
    []( UserProfilPage& userProfile )
    {
        return userProfile.isReady();
    });

    if( isEveryOneReady )
    {
        this->views->setCurrentIndex( this->gameSelectionViewIndex );
    }
}
