#include "replace.hpp"

void	ft_replace(std::ifstream &file, std::string const &name, std::string const &from, std::string const &to)
{
	std::ofstream	newfile;
	std::string		text;
	std::size_t		pos;
	std::size_t		i = 0;

	newfile.open(name + ".replace", std::ofstream::trunc);
    if (!newfile)
    {
        std::cerr << "Error: Unable to create the output file" << std::endl;
        file.close();
        newfile.close();
        return ;
    }
	std::getline(file, text, '\0');
	pos = text.find(from);
	for (;pos != std::string::npos; pos = text.find(from, i))
	{
		for (; i < pos; ++i)
			newfile << text[i];
		newfile << to;
		i += from.size();
	}
	for (; i < text.size(); ++i)
		newfile << text[i];
}