
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_toupper(void)
{
	int errorState = 1;

	for (int i = 0; i < 200; i ++)
	{
       
		if (toupper(i) != ft_toupper(i))
		{
			printf("========================\n");
			printf("Error: test_ft_toupper\n");
			printf("toupper(i = %d) = || %c ||, ft_toupper(i = %d)= || %c || \n", i, toupper(i), i, ft_toupper(i));
			printf("========================\n");
			errorState = 0;
		} 
	}

	if (errorState == 1)
	{
		printf("test_ft_toupper: OK!\n");
	}
}