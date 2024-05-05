
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_isprint(void)
{
	int testChar = 0;
	int errorState = 1;
	
	while (testChar <= 127)
	{
		if (isprint(testChar) == 0 && ft_isprint(testChar) != 0)
		{
			printf("========================\n");
			printf("Error: ft_isprint_test\n");
			printf("isprint(%d) = 0 but ft_isprint(%d) = %d\n", testChar, testChar, ft_isprint(testChar));
			printf("========================\n");
			errorState = 0;
		} else if (isprint(testChar) > 0 && ft_isprint(testChar) <= 0) {
			printf("========================\n");
			printf("Error: ft_isprint_test\n");
			printf("isprint(%c) = %d but ft_isprint(%c) = %d\n", testChar, isprint(testChar), testChar, ft_isprint(testChar));
			printf("========================\n");
			errorState = 0;
		}
		testChar++;
	}
	if (errorState == 1)
	{
		printf("test_ft_isprint: OK!\n");
	}
	
}