#include "GameStatPanel.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

GameStatPanel::GameStatPanel(QWidget *parent) : QWidget(parent)
{
    this->returnToGameSelection = new QPushButton( "Retourner à la sélection des jeux", this);
    QObject::connect( returnToGameSelection, SIGNAL(clicked()), this, SIGNAL( goBackToGameSelection() ) );

    this->pScoreLbl = new QLabel( this);

    QVBoxLayout* scoreAndButtonLayout = new QVBoxLayout();
    scoreAndButtonLayout->addWidget( this->pScoreLbl );
    scoreAndButtonLayout->addWidget( returnToGameSelection );

    this->setLayout( scoreAndButtonLayout );
}

void GameStatPanel::process( GamePadMsgType gamepadMsg_ )
{
    if( isGamepadBBtn( gamepadMsg_ ) )
    {
        this->returnToGameSelection->animateClick();
    }
}

void GameStatPanel::showStatForGame( const QString& gameName_, const std::vector< Score >& highScores_ )
{
    this->pScoreLbl->setText( "Aucune statistique pour " + gameName_ );
}

