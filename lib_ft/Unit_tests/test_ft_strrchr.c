
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_strrchr(void)
{
	int errorState = 1;
	char testStringArr[] = "012340123401234567";

	for (int i = 0; i < 250; i++)
	{
		if (strrchr(testStringArr, i) != ft_strrchr(testStringArr, i))
		{
			printf("========================\n");
			printf("Error: test_ft_strrchr\n");
			printf("strrchr(i = %d) = %p, ft_strrchr(i = %d) = %p \n", i, strrchr(testStringArr, i), i, ft_strrchr(testStringArr, i) );
			printf("========================\n");
			errorState = 0;
		} 
	}
	if (errorState == 1)
	{
		printf("test_ft_strrchr: OK!\n");
	}
	
}