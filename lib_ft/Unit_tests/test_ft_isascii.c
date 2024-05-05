#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_isascii(void)
{
	int testChar = 0;
	int errorState = 1;
	
	while (testChar <= 127)
	{
		if (isascii(testChar) == 0 && ft_isascii(testChar) != 0)
		{
			printf("========================\n");
			printf("Error: test_ft_isascii\n");
			printf("isascii(%c) = 0 but ft_isascii(%c) = %d\n", testChar, testChar, ft_isascii(testChar));
			printf("========================\n");
			errorState = 0;
		} else if (isascii(testChar) > 0 && ft_isascii(testChar) <= 0) {
			printf("========================\n");
			printf("Error: test_ft_isascii\n");
			printf("isascii(%c) = %d but ft_isascii(%c) = %d\n", testChar, isascii(testChar), testChar, ft_isascii(testChar));
			printf("========================\n");
			errorState = 0;
		}
		testChar++;
	}
	if (errorState == 1)
	{
		printf("test_ft_isascii: OK!\n");
	}
	
}