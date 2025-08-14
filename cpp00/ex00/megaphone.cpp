#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if(ac > 0)
    {
        if(ac == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        else
        {
            std::string chare;
            for(int i = 1; i < ac; i++)
                chare += av[i];
            for (size_t j = 0; j < chare.length(); j++)
            {
                chare[j] = toupper(chare[j]);
                std::cout << chare[j];
            }
            std::cout << std::endl;
        }
        return(0);
    }
}