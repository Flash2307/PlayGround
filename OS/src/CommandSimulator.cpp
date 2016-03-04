#include "CommandSimulator.h"

#include <QKeyEvent>

#include "HomeWindow.h"

CommandSimulator::CommandSimulator() :
    userIndex( 0 )
{

}

bool CommandSimulator::eventFilter( QObject* obj_, QEvent* event_ )
{
    HomeWindow* pWindow = (HomeWindow*)obj_;

    if( event_->type() == QEvent::KeyPress )
    {
        QKeyEvent* pKey = static_cast<QKeyEvent*>( event_ );

        switch( pKey->key() )
        {
        case Qt::Key_Up:
            pWindow->newMessageArrive( makeMessage( this->userIndex, true ) );
            return true;
        case Qt::Key_Down:
            pWindow->newMessageArrive( makeMessage( this->userIndex, false, true ) );
            return true;
        case Qt::Key_Left:
            pWindow->newMessageArrive( makeMessage( this->userIndex, false, false, true ) );
            return true;
        case Qt::Key_Right:
            pWindow->newMessageArrive( makeMessage( this->userIndex, false, false, false, true ) );
            return true;
        case Qt::Key_A:
            pWindow->newMessageArrive( makeMessage( this->userIndex, false, false, false, false, true ) );
            return true;
        case Qt::Key_B:
            pWindow->newMessageArrive( makeMessage( this->userIndex, false, false, false, false, false, true ) );
            return true;
        case Qt::Key_C:
            pWindow->newMessageArrive( makeMessage( this->userIndex ) );
            return true;
        case Qt::Key_D:
            pWindow->newMessageArrive( makeMessage( this->userIndex, false, false, false, false, false, false, true ) );
            return true;
        case Qt::Key_0:
            userIndex = 0;
            return true;
        case Qt::Key_1:
            userIndex = 1;
            return true;
        case Qt::Key_2:
            userIndex = 2;
            return true;
        case Qt::Key_3:
            userIndex = 3;
            return true;
        };
    }

    return false;
}
