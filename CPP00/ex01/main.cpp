#include "phonebook.hpp"

int main(void)
{
    std::string cmd;
    Contact    book[8];
    int     count;

    count = 0;
    while (1)
    {

        getline(std::cin, cmd);
        if (cmd == "EXIT")
            break ;
        else if (cmd == "SEARCH")
        {
            if (!count)
                std::cout << "Empty phonebook. \"ADD\" to create new content." << std::endl;
            else
                search(book, count);
        }
        else if (cmd == "ADD")
        {
            
        }
        else
            std::cout << "Invalid command. Please enter either \"ADD\" \"SEARCH\" or \"EAXIT\"" << std::endl;
    }
    return 0;
}