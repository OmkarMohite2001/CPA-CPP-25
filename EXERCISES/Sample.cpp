#include <iostream>

class Base
{
    public:
        Base()
        {

        }

        virtual void show()
        {
            std::cout << "Base class show()" << std::endl;
        }
};

class Derived : public Base
{
    public:
        Derived()
        {

        }

        void show() override
        {
            std::cout << "Derived class show()" << std::endl;
        }
};

void test_Inheritance();

int main(void)
{
    test_Inheritance();
    return 0;
}

void test_Inheritance()
{
    Base* pBaseobj = new Derived();

    pBaseobj->show();

    delete pBaseobj;
    pBaseobj = 0;
}