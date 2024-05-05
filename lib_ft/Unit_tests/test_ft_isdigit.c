#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_isdigit(void)
{
    int i = 0;
	int errorState = 1;

	while (i <= 127)
	{
		if (isdigit(i) == 0 && ft_isdigit(i) != 0)
		{
			printf("========================\n");
			printf("Error: ft_isdigit\n");
			printf("isdigit(%c) = 0 but ft_isdigit(%c) = %d\n", i, i, ft_isdigit(i));
			printf("========================\n");
			errorState = 0;
		} else if (isdigit(i) > 0 && ft_isdigit(i) <= 0) {
			printf("========================\n");
			printf("Error: isdigit\n");
			printf("isdigit(%c) = %d but ft_isdigit(%c) = %d\n", i, isdigit(i), i, ft_isdigit(i));
			printf("========================\n");
			errorState = 0;
		}
		i++;
	}

	if (errorState == 1)
	{
		printf("test_ft_isdigit: OK!\n");
	}
}