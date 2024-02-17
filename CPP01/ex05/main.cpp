#include "Harl.hpp"

int main()
{
    Harl    harl;

    std::cout << "Test error cases:" << std::endl;
    harl.complain("");
    harl.complain("hi");
    std::cout << std::endl;
    std::cout << "Test normal cases:" << std::endl;
    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("ERROR");
    std::cout << std::endl;
    return 0;
}