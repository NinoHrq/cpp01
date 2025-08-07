# include <string>
# include <iostream>

int main()
{
    std::string message = " HI THIS IS BRAIN";

    std::string *stringPTR = &message;
    std::string& stringREF = message;

    std::cout << "\n\n              Memory             \n";
    std::cout << "----------------------------------\n\n";
    std::cout << "The memory address of message is" << &message << "\n" << std::endl;
    std::cout << "The memory address of stringPTR is " << stringPTR << " \n " << std::endl;
    std::cout << "The memory address of stringREF is " << &stringREF << " \n " << std::endl;
    std::cout << "----------------------------------\n\n";


    std::cout << "\n\n            Value                \n";
    std::cout << "----------------------------------\n\n";
    std::cout << "The value of message is" << message << " \n " << std::endl;
    std::cout << "The value of stringPTR is" << *stringPTR << " \n " << std::endl;
    std::cout << "The value of stringREF is" << stringREF << " \n " << std::endl;
    std::cout << "----------------------------------\n\n";

    return 0;
}
