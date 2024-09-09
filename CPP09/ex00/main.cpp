#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Usage: ./BitcoinExchange <data_file>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;

	exchange.parse(av[1]);

	return (0);
}