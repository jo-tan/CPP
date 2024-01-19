#include <iostream>
#include <cctype>
#include <climits>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; ++i)
		{
			for(int j = 0; av[i][j] != '\0'; ++j)
			{
				if (av[i][j] < CHAR_MIN || av[i][j] > CHAR_MAX)
					std::cerr << "Invalid character detected."<< std::endl;
				else
					std::cout << static_cast<char>(toupper(av[i][j]));
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}