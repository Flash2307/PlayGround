#ifndef COMMANDSIMULATOR_H
#define COMMANDSIMULATOR_H

#include <QObject>

class CommandSimulator : public QObject
{
    Q_OBJECT
public:
    CommandSimulator();
protected:
    bool eventFilter(QObject* obj, QEvent* event);
private:
    size_t userIndex;
};

#endif // COMMANDSIMULATOR_H
