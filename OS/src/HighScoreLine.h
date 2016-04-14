#ifndef HIGHSCORELINE_H
#define HIGHSCORELINE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class HighScoreLine : public QWidget
{
public:
    HighScoreLine(QWidget* parent, QPixmap pict, QString name, QString score);

private:
    QHBoxLayout* layoutGlobal = nullptr;
    QLabel* labelProfilePicture = nullptr;
    QLabel* labelProfileName = nullptr;
    QLabel* labelScore = nullptr;
};

#endif // HIGHSCORELINE_H
