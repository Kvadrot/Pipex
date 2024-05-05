
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_isalpha(void)
{
	int testChar = 0;
	int errorState = 1;
	
	while (testChar <= 127)
	{
		if (isalpha(testChar) == 0 && ft_isalpha(testChar) != 0)
		{
			printf("========================\n");
			printf("Error: ft_isalpha_test\n");
			printf("isalpha(%c) = 0 but ft_isalpha(%c) = %d\n", testChar, testChar, ft_isalpha(testChar));
			printf("========================\n");
			errorState = 0;
		} else if (isalpha(testChar) > 0 && ft_isalpha(testChar) <= 0) {
			printf("========================\n");
			printf("Error: ft_isalpha_test\n");
			printf("isalpha(%c) = %d but ft_isalpha(%c) = %d\n", testChar, isalpha(testChar), testChar, ft_isalpha(testChar));
			printf("========================\n");
			errorState = 0;
		}
		testChar++;
	}
	if (errorState == 1)
	{
		printf("test_ft_isalpha: OK!\n");
	}
	
}