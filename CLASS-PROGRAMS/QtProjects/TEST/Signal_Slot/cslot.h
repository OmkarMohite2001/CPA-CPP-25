#ifndef CSLOT_H
#define CSLOT_H

#include <QObject>

class CSlot : public QObject
{
    Q_OBJECT
public:
    CSlot();
public slots:
    void handlerFunction(int n1, int n2);

};

#endif // CSLOT_H
