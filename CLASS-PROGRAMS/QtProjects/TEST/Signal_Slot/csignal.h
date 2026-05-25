#ifndef CSIGNAL_H
#define CSIGNAL_H

#include <QObject>

class CSignal : public QObject
{
    Q_OBJECT
public:
    CSignal();
    void trigger(int dataOne, int dataTwo);
signals:
    void f(int, int);
};

#endif // CSIGNAL_H
