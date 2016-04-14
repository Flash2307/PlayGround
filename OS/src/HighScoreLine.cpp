#include "HighScoreLine.h"


HighScoreLine::HighScoreLine(QWidget* parent, QPixmap pict, QString name, QString score):QWidget(parent)
{
    layoutGlobal = new QHBoxLayout(this);
    setLayout(layoutGlobal);
    setFixedHeight(250);

    labelProfilePicture = new QLabel(this);
    labelProfilePicture->setPixmap(pict);
    labelProfilePicture->setFixedSize(100, 100);
    labelProfilePicture->setScaledContents(true);
    layoutGlobal->addWidget(labelProfilePicture);

    labelProfileName = new QLabel(this);
    labelProfileName->setText(name);
    labelProfileName->setFont( QFont( "Arial", 24, QFont::Bold ) );
    layoutGlobal->addWidget(labelProfileName);

    labelScore = new QLabel(this);
    labelScore->setText(score);
    labelScore->setFont( QFont( "Arial", 24, QFont::Bold ) );
    layoutGlobal->addWidget(labelScore);
}
