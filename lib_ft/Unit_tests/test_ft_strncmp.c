
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void test_ft_strncmp(void)
{
	int errorState = 1;
	char testStringArr[] = "012340123401234567";
	char testStringArr1[] = "012340123401267";
	int byteLimit = 40;



	for (int i = 0; i > byteLimit; i++)
	{

		int origResult = strncmp(testStringArr, testStringArr1, i);
		int mineResult = ft_strncmp(testStringArr, testStringArr1, i);

		if ( origResult != mineResult)
		{
			printf("========================\n");
			printf("Error: test_ft_strncmp\n");
			printf("byteLimit = %d\n" , i);
			printf("strncmp() = %d, ft_strncmp() = %d \n", origResult, mineResult);
			printf("========================\n");
			errorState = 0;
		} 
	}

	if (errorState == 1)
	{
		printf("test_ft_strncmp: OK!\n");
	}
}