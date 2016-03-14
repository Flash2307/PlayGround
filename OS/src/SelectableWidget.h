#ifndef SELECTABLEWIDGET_H
#define SELECTABLEWIDGET_H

#include <QWidget>

class SelectableWidget : public QWidget
{
public:
    SelectableWidget();

    void setSelected( bool isSelected_ );
    bool isSelected() const;
protected:
    void paintEvent(QPaintEvent *pe);
private:
    bool selected;
};

#endif // SELECTABLEWIDGET_H
