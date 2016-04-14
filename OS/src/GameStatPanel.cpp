#include "GameStatPanel.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

GameStatPanel::GameStatPanel(QWidget *parent) : QWidget(parent)
{
    scoreAndButtonLayout = new QVBoxLayout();
    setLayout( scoreAndButtonLayout );

    labelGameName = new QLabel(this);
    labelGameName->setFont( QFont( "Arial", 48, QFont::Bold ) );
    labelGameName->setText("GameName");
    scoreAndButtonLayout->addWidget(labelGameName);
}

void GameStatPanel::process( GamePadMsgType gamepadMsg_ )
{
    if( isGamepadBBtn( gamepadMsg_ ) )
    {
        //this->returnToGameSelection->animateClick();
    }
}

void GameStatPanel::showStatForGame(const QString& gameName_)
{
    labelGameName->setText("HighScore for game " + gameName_);

    for(HighScoreLine* line : scoreLines)
        delete line;

    scoreLines.clear();

    std::vector<Score> scores = db.getHightScores(gameName_, 0);

    for(Score& score : scores)
    {
        HighScoreLine* aa = new HighScoreLine(this, score.userPict, score.userName, QString::number(score.score));
        scoreLines.emplace_back(aa);
        scoreAndButtonLayout->addWidget(aa);
    }
}

