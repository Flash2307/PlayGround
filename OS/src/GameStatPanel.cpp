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
    if( highScores_.empty() )
    {
        this->pScoreLbl->setText( "Aucune statistique pour " + gameName_ );
    }
    else
    {
        QString statText( "Statistiques pour " + gameName_ );

        for( Score score : highScores_ )
        {
            statText += score.userName;
            statText += ": ";
            statText += QString("%1").arg( score.score );
            statText += "\n";
        }

        this->pScoreLbl->setText( statText );
    }
}

