
#include "../lib_ft/libft.h"
#include "libft_tests.h"


void printError(char *orig, char *test)
{
	printf("========================\n");
	printf("Error: ft_calloc_test\n");
	printf("tes_ft_calloc() = %s but ft_calloc() = %s\n", orig, test);
	printf("========================\n");

}

void test_ft_calloc()
{
	size_t terminalCounter = 0;
 	char *origArr;
	char *testArr;
	size_t bytesAmount = 201;
	int errorSate = 1;

	origArr = calloc(bytesAmount, sizeof(origArr));
	testArr = ft_calloc(bytesAmount, sizeof(testArr));

	if (memcmp(origArr, testArr, bytesAmount) != 0)
	{
		printError(origArr, testArr);
		errorSate = 0;
	}

	while (terminalCounter < bytesAmount && testArr[terminalCounter] == '\0')
	{
		terminalCounter++;
	}
	if (terminalCounter != bytesAmount)
	{
		printError(origArr, testArr);
		errorSate = 0;
	}
	if (errorSate == 1)
	{
		printf("test_ft_calloc: OK!\n");
	}
}