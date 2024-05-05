
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_strlen(void)
{
	int errorState = 1;
	char testStringArr[] = "0123456789";
	char testStringArr1[] = "";
	char testStringArr2[] = "01234\n \0 1234123";
	char testStringArr3[] = "\0 01234\n 1234123";
	char *testArr[] = { testStringArr, testStringArr1, testStringArr2, testStringArr3 };

	for (int i = 0; i < 4; i++)
	{
		if (strlen(testArr[i]) != ft_strlen(testArr[i]))
		{
			printf("========================\n");
			printf("Error: test_ft_strlen\n");
			printf("strlen(i = %d) = %ld, ft_strlen(i = %d) = %ld \n", i, strlen(testArr[i]), i, ft_strlen(testArr[i]));
			printf("========================\n");
			errorState = 0;
		} 
	}
	if (errorState == 1)
	{
		printf("test_ft_strlen: OK!\n");
	}
	
}