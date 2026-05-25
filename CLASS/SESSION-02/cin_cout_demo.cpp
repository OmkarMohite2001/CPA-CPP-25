#include <iostream>
#include <string>

int main(void)
{

    int i_num;
    float f_num;
    std::string str;

    std::cout << "Enter an integer Value:";
    std::cin >> i_num;
    std::cout << "Entered integer is :"<< i_num << "\n";

    std::cout << "Enter an fractional Value:";
    std::cin >> f_num;
    std::cout << "Entered fractional is :"<< f_num << "\n";

    std::cout << "Enter your name:";
    std::cin >> str;
    std::cout << "Your name is :"<< str << "\n";

    return 0;
}
