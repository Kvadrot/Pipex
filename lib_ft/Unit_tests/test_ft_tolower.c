#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_tolower(void)
{
	int errorState = 1;

	for (int i = 0; i < 200; i ++)
	{
       
		if (tolower(i) != ft_tolower(i))
		{
			printf("========================\n");
			printf("Error: test_ft_tolower\n");
			printf("tolower(i = %d) = || %c ||, ft_tolower(i = %d)= || %c || \n", i, tolower(i), i, ft_tolower(i));
			printf("========================\n");
			errorState = 0;
		} 
	}

	if (errorState == 1)
	{
		printf("test_ft_tolower: OK!\n");
	}
}