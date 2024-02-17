#include "replace.hpp"

int		main(int ac, char **av)
{
	std::ifstream	inputFile;

	if (ac != 4)
	{
		std::cerr << "Invalid arguments. HINT: <input_file> <search_string> <replace_string>" << std::endl;
		return 1;
	}
    if (std::string(av[1]).empty())
    {
        std::cerr << "Error: No input file" << std::endl;
		return 1;
    }
    inputFile.open(av[1]);
	if (!inputFile)
		std::cerr << "Error: Unable to open file '" << av[1] << "'" << std::endl;
	else if (std::string(av[2]).empty() || std::string(av[3]).empty())
		std::cerr << "search and/or replace string is empty." << std::endl;
	else
	{
		ft_replace(inputFile, av[1], av[2], av[3]);
		return 0;
	}
	inputFile.close();
	return 1;
}