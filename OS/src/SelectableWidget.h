#ifndef SELECTABLEWIDGET_H
#define SELECTABLEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

#include "Game.h"

class QPushButton;

enum GameCommand
{
    LAUNCH,
    SHOW_STATS
};

class SelectableWidget : public QWidget
{
public:
    SelectableWidget( QWidget* parent, Game game, GameCommand command_);

    inline void setSelected( bool isSelected_ ) {selected = isSelected_;setGameCommand(LAUNCH);}
    inline bool isSelected() const {return selected;}

    inline GameCommand getCommand() const {return command;}
    inline QString getGamePath() const {return game.getPath();}
    inline Game getGame() const { return game; }

    void nextCommand();
    void previousCommand();

protected:
    void paintEvent(QPaintEvent *pe);
    void setGameCommand( GameCommand command_ );

private:
    bool selected;

    GameCommand command;
    Game game;

    QVBoxLayout* layoutGlobal;
    QLabel* labelGameName;
    QLabel* labelGameImage;
    QLabel* labelGameDescription;
    QLabel* labelStartGame;
    QLabel* labelStatistics;
};

#endif // SELECTABLEWIDGET_H
