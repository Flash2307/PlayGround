#ifndef SELECTABLEWIDGET_H
#define SELECTABLEWIDGET_H

#include <QWidget>

class QPushButton;

enum class GameCommand
{
    Lauch,
    ShowStat,
    LoadSavedGame
};

class SelectableWidget : public QWidget
{
public:
    SelectableWidget( const QString& gameName_, GameCommand command_, QPushButton* pCommandBtn_ );

    void setSelected( bool isSelected_ );
    bool isSelected() const;

    void setGameCommand( GameCommand command_ );
    GameCommand getCommand() const;

    void nextCommand();
    void previousCommand();
protected:
    void paintEvent(QPaintEvent *pe);
private:
    QString gameName;
    GameCommand command;
    QPushButton* pCommandBtn;
    bool selected;
};

#endif // SELECTABLEWIDGET_H
