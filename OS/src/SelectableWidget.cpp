#include "SelectableWidget.h"

#include <cassert>

#include <QPainter>
#include <QPushButton>

SelectableWidget::SelectableWidget( const QString& gameName_, GameCommand command_, QPushButton* pCommandBtn_ ) :
    gameName( gameName_ ),
    command( command_ ),
    pCommandBtn( pCommandBtn_ ),
    selected( false )
{
    assert( this->pCommandBtn != nullptr );
    this->setGameCommand( command_ );
}

void SelectableWidget::setSelected( bool isSelected_ )
{
    this->selected = isSelected_;
}

bool SelectableWidget::isSelected() const
{
    return this->selected;
}

void SelectableWidget::setGameCommand( GameCommand command_ )
{
    this->command = command_;

    switch( this->command )
    {
    case GameCommand::Lauch:
        this->pCommandBtn->setText( QString( "Débuter %1" ).arg( this->gameName ) );
        break;
    case GameCommand::LoadSavedGame:
        this->pCommandBtn->setText( QString( "Charger une partie de %1" ).arg( this->gameName ) );
        break;
    case GameCommand::ShowStat:
        this->pCommandBtn->setText( QString( "Voir les statistiques de %1" ).arg( this->gameName ) );
        break;
    }
}

GameCommand SelectableWidget::getCommand() const
{
    return this->command;
}

void SelectableWidget::nextCommand()
{
    switch( this->command )
    {
    case GameCommand::Lauch:
        this->setGameCommand( GameCommand::LoadSavedGame );
        break;
    case GameCommand::LoadSavedGame:
        this->setGameCommand( GameCommand::ShowStat );
        break;
    case GameCommand::ShowStat:
        this->setGameCommand( GameCommand::Lauch );
        break;
    }
}

void SelectableWidget::previousCommand()
{
    switch( this->command )
    {
    case GameCommand::Lauch:
        this->setGameCommand( GameCommand::ShowStat );
        break;
    case GameCommand::LoadSavedGame:
        this->setGameCommand( GameCommand::Lauch );
        break;
    case GameCommand::ShowStat:
        this->setGameCommand( GameCommand::LoadSavedGame );
        break;
    }
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
