#include <QObject> 

class ETest 
{
    Q_OBJECT 

signals: 
    void myEvent(int,int); 

public: 
    void raiseEvent(); 
}; 