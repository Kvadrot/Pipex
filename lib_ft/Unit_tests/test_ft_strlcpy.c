
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void test_ft_strlcpy(void)
{
	char test_arr[20] = "2\0";
	char test_arr1[20] = "0123456789 ";

	char testOrig_arr[20] = "2\0";
	char testOrig_arr1[20] = "0123456789 ";
	int testBytes = 1;

	int errorState = 1;
	size_t origRes = strlcpy(testOrig_arr, testOrig_arr1, testBytes);
	size_t mineRes = ft_strlcpy(test_arr, test_arr1, testBytes);

	if (origRes != mineRes)
	{
		printf("========================\n");
        printf("Error: test_ft_strlcpy\n");
		printf("strlcpy() = %ld \n", origRes);
		printf("ft_strlcpy() = %ld \n", mineRes);
        printf("test_arr[] = %s ", test_arr);
		printf("testOrig_arr1[] = %s\n", testOrig_arr);
        printf("========================\n");
        errorState = 0;
	} else  if (strcmp(test_arr, testOrig_arr) != 0)
	{
		printf("========================\n");
        printf("Error: test_ft_strlcpy\n");
        printf("test_arr[] = %s ", test_arr);
		printf("testOrig_arr1[] = %s\n", testOrig_arr);
        printf("========================\n");
        errorState = 0;
	}

	if (errorState == 1)
    {
        printf("test_ft_strlcpy: OK!\n");
    }

}