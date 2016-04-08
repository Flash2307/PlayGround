#include "SelectableWidget.h"

#include <cassert>

#include <QPainter>
#include <QPushButton>


SelectableWidget::SelectableWidget( QWidget* parent, Game game, GameCommand command_ ) :
    QWidget(parent),
    game(game),
    command( command_ ),
    selected( false )
{   
    this->setFixedWidth(420);

    layoutGlobal = new QVBoxLayout(this);
    this->setLayout(layoutGlobal);
    layoutGlobal->setAlignment(Qt::AlignHCenter);

    labelGameName = new QLabel(game.getName(), this);
    labelGameName->setWordWrap( true );
    labelGameName->setFont( QFont( "Arial", 48, QFont::Bold ) );
    layoutGlobal->addWidget(labelGameName);

    labelGameImage = new QLabel(this);
    labelGameImage->setFixedSize(400, 400);
    labelGameImage->setMargin(20);
    labelGameImage->setPixmap(game.getPicture());
    labelGameImage->setScaledContents(true);
    layoutGlobal->addWidget(labelGameImage);

    labelGameDescription = new QLabel(game.getDescription(), this);
    labelGameDescription->setWordWrap( true );
    labelGameDescription->setFont( QFont( "Arial", 18 ) );
    labelGameDescription->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    labelGameDescription->setAlignment(Qt::AlignTop);
    layoutGlobal->addWidget(labelGameDescription);

    labelStartGame = new QLabel("Lancer le jeu", this);
    labelStartGame->setAlignment(Qt::AlignCenter);
    labelStartGame->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    labelStartGame->setFixedHeight(50);
    labelStartGame->setFont( QFont( "Arial", 24, QFont::Bold ) );
    layoutGlobal->addWidget(labelStartGame);

    labelStatistics = new QLabel("Voir statistiques", this);
    labelStatistics->setAlignment(Qt::AlignCenter);
    labelStatistics->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    labelStatistics->setFixedHeight(50);
    labelStatistics->setFont( QFont( "Arial", 24, QFont::Bold ) );
    layoutGlobal->addWidget(labelStatistics);


    this->setGameCommand( command_ );
}

void SelectableWidget::setGameCommand( GameCommand command_ )
{
    this->command = command_;
    labelStartGame->setStyleSheet("QLabel { background-color: #00000000; border: 1px solid black; }");
    labelStatistics->setStyleSheet("QLabel { background-color: #00000000; border: 1px solid black; }");

    if(selected && command == LAUNCH)
        labelStartGame->setStyleSheet("QLabel { background-color: #FF00FF00; border: 1px solid black; }");
    else if(selected && command == SHOW_STATS)
        labelStatistics->setStyleSheet("QLabel { background-color: #FF00FF00; border: 1px solid black; }");
}

void SelectableWidget::nextCommand()
{
    if(command != SHOW_STATS)
        setGameCommand((GameCommand)(command + 1));
}

void SelectableWidget::previousCommand()
{
    if(command != LAUNCH)
        setGameCommand((GameCommand)(command - 1));
}

void SelectableWidget::paintEvent( QPaintEvent* pPaintEvent_ )
{
    QPainter painter(this);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();

    if( this->selected )
        painter.setBrush( QBrush( QColor( 0, 255, 0 ) ) );
    else
        painter.setBrush( QBrush( QColor( 255, 255, 255 ) ) );

    //painter.drawRect( QRect( 0, 0, width, height ) );
    painter.setBrush( QBrush( QColor( 255, 255, 255 ) ) );
    painter.drawRect( QRect( 5, 5, width - 11, height - 11 ) );
    painter.end();

    QWidget::paintEvent( pPaintEvent_ );
}
