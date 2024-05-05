
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_isalnum(void)
{
	int testChar = 0;
	int errorState = 1;
	
	while (testChar <= 127)
	{
		if (isalnum(testChar) == 0 && ft_isalnum(testChar) != 0)
		{
			printf("========================\n");
			printf("Error: ft_isalnum_test\n");
			printf("isalnum(%c) = 0 but ft_isalnum(%c) = %d\n", testChar, testChar, ft_isalnum(testChar));
			printf("========================\n");
			errorState = 0;
		} else if (isalnum(testChar) > 0 && ft_isalnum(testChar) <= 0) {
			printf("========================\n");
			printf("Error: ft_isalnum_test\n");
			printf("isalnum(%c) = %d but ft_isalnum(%c) = %d\n", testChar, isalnum(testChar), testChar, ft_isalnum(testChar));
			printf("========================\n");
			errorState = 0;
		}
		testChar++;
	}
	if (errorState == 1)
	{
		printf("test_ft_isalnum: OK!\n");
	}
	
}