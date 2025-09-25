#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(std::toupper
				(static_cast<unsigned char>(argv[i][j])));
	}
	std::cout << std::endl;
	return 0;
}

