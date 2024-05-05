#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_memset(void)
{
	int errorState = 1;
	char newSymb = 'd';

	char testStringArr[100] = "";
	char testStringArr1[] = "";
	char testStringArr2[] = "0123456";
	char testStringArr3[] = "\0\0\0\0\0";

	char testCustArr[100] = "";
	char testCustArr1[] = "";
	char testCustArr2[] = "0123456";
	char testCustArr3[] = "\0\0\0\0\0";

	char *fatherTestArr[] = { testStringArr, testStringArr1, testStringArr2, testStringArr3 };
	char *fatherTestCustArr[] = { testCustArr, testCustArr1, testCustArr2, testCustArr3 };

    for (int i = 0; i < 4; i++)
    {
        for (int counter = 0; counter < 100; counter++)
        {

            // Call the functions to modify the strings
            char *strOrig = memset(fatherTestArr[i], newSymb, counter);
            char *strMine = ft_memset(fatherTestCustArr[i], newSymb, counter);

            // Compare the modified strings
            if (strncmp(strOrig, strMine, counter) != 0)
            {
                printf("========================\n");
                printf("Error: test_ft_memset\n");
				printf("i = %d, counter = %d testingArrSize = %d \n", i, newSymb, counter);
                printf("memset(testingArr%d) strcmp(strOrig, strMine) = %d \n", i, strcmp(strOrig, strMine));
                printf("========================\n");
                errorState = 0;
            }
        }
    }

    if (errorState == 1)
    {
        printf("test_ft_memset: OK!\n");
    }
	
}