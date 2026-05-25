#include <QApplication> 
#include "ETest.hpp"
#include "STest.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv); 

    ETest et1, et2; 
    STest st1, st2; 

    std::cout << "&st1:" << std::hex << &st1 << std::endl; 
    std::cout << "&st2:" << std::hex << &st2 << std::endl; 
     
    QObject::connect(&et1, SIGNAL(myEvent), &st1, SLOT(myHandler)); 
    QObject::connect(&et2, SIGNAL(myEvent), &st2, SLOT(myHandler)); 

    et1.raiseEvent();   // emit myEvent(100, 200) -> st1.myHandler(100, 200) -> &st1 addr, x:100, y:200
    std::cout << "------SEPARATOR------" << std::endl; 
    et2.raiseEvent();   // ETest::raiseEvent(&et2) -> emit myEvent(100, 200) -> st2.myHander() -> &st2, x:100, y:200
    
    return app.exec(); 
}