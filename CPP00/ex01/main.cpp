#include "phonebook.hpp"

int main(void)
{
    std::string buf;
    Book    book[8];
    int     count;

    count = 0;
    while (1)
    {
        getline(std::cin, buf);
        if (buf == "EXIT")
            break ;
        else if (buf == "SEARCH")
        {
            if (!count)
                std::cout << "Empty phonebook"
            search(book, count);
        }
    }
    return 0;
}