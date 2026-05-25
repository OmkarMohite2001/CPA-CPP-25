#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public slots:
    void doAdd(int,int);
    void doSubtract(int,int);
    void doMultiply(int,int);
    void doDivide(int, int);
};


#endif
