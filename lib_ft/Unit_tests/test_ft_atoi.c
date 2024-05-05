
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_atoi()
{
	int origVal;
	int mineVal;
    char str1[] = "";
	char str2[] = "   2123123"; // corrected
	char str3[] = " --2"; // corrected
	char str4[] = "   +-2\0"; // corrected
	char str5[] = "-2147483648";
	char str6[] = "2147483648";
	char str7[] = "2147483647";
	char str8[] = "+2147483647";
	char str9[] = "-2147483647";
	char str10[] = "   -0"; // corrected
	char *mainStr[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10}; // corrected
	int numCases = sizeof(mainStr) / sizeof(mainStr[0]);
	int errorState = 1;

    for (int i = 0; i < numCases; i++)
    {
		origVal = atoi(mainStr[i]);
		mineVal = ft_atoi(mainStr[i]);

        if (origVal != mineVal)
        {
            printf("========================\n");
            printf("Error: test_ft_atoi\n");
            printf("i = %d\n", i);
            printf("atoi() = %d \n", origVal);
            printf("ft_atoi() = %d \n", mineVal);
            printf("========================\n");
            errorState = 0;
        }
    }

    if (errorState == 1)
    {
        printf("test_ft_atoi: OK!\n");
    }
}