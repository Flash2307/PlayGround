#include "SelectableWidget.h"

#include <QPainter>

SelectableWidget::SelectableWidget() :
    selected( false )
{

}

void SelectableWidget::setSelected( bool isSelected_ )
{
    this->selected = isSelected_;
}

bool SelectableWidget::isSelected() const
{
    return this->selected;
}

void SelectableWidget::paintEvent( QPaintEvent* pPaintEvent_ )
{
    QPainter painter(this);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();

    if( this->selected )
    {
        painter.setBrush( QBrush( QColor( 0, 255, 0 ) ) );
    }
    else
    {
        painter.setBrush( QBrush( QColor( 255, 0, 0 ) ) );
    }

    painter.drawRect( QRect( 0, 0, width, height ) );
    painter.setBrush( QBrush( QColor( 255, 255, 255 ) ) );
    painter.drawRect( QRect( 3, 3, width - 6, height - 6 ) );
    painter.end();

    QWidget::paintEvent( pPaintEvent_ );
}
