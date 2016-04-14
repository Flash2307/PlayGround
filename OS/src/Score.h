#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <QPixmap>

struct Score
{
    Score(QString userName, QPixmap userPict, int score):
        userName(userName), userPict(userPict), score(score){}

    QPixmap userPict;
    QString userName;
    int score;
};

#endif // SCORE_H_INCLUDED

