// #include <iostream>

// int valid_arg(int argc, char **argv)
// {
// 	int i;
// 	int j;
	
// 	i = 1;
// 	j = 0;
// 	if (argc != 2)
// 	{
// 		if (argv[i][j + 1])
// 			return (1);
// 	}
// 	while (argv[i])
// 	{
// 		while (argv[i][j])
// 		{
// 			// std::cout << "DEBUG: " << argv[i][j] << std::endl;
// 			if (argv[i][j] == '-' || (argv[i][j] != ' ' && !(argv[i][j] >= '0' && argv[i][j] <= '9')))
// 				return (1);	
// 			j++;
// 		}
// 		i++;
// 	}

// 	return (0);
// }

#include <iostream>

int main()
{
	// if (argc != 1)
	// {
	// 	if (valid_arg(argc, argv))
	// 	{
	// 		std::cout << "1Error" << std::endl;
	// 		return (1);
	// 	}
	// 	std::cout << "PASS CHECK!" << std::endl;
	// }
	// else
	// {
	// 	std::cout << "Error" << std::endl;
	// 	return (1);
	// }

	if (!isdigit(-1))
		std::cout << "done\n";
}
