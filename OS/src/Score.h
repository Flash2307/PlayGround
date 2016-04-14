#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

struct Score
{
    Score(QString userName, int score):
        userName(userName), score(score){}

    QString userName;
    int score;
};

#endif // SCORE_H_INCLUDED

