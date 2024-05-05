
#include "../lib_ft/libft.h"
#include "libft_tests.h"

int	ft_test_same_arr(void) {
	char source[] = "012345";
	char org_source[] = "012345";
	size_t localTestBytes = 3;
	size_t origRes = strlcat(org_source + 1, org_source, localTestBytes);
	size_t mineRes = ft_strlcat(source + 1, source, localTestBytes);
	int result = 4;
	if (origRes != mineRes || strcmp(source, org_source) != 0)
	{
		printf("========================\n");
        printf("Error: test_ft_strlcat\n");
		printf("localTestBytes = %ld\n", localTestBytes);
		printf("strlcat() = %ld \n", origRes);
		printf("ft_strlcat() = %ld \n", mineRes);
		printf("testOrig_arr1[] = %s\n", org_source);
        printf("test_arr[] = %s\n", source);
        printf("========================\n");
        result = 0;
	} else  if (strcmp(source, org_source) != 0)
	{
		printf("========================\n");
        printf("Error: test_ft_strlcat\n");
		printf("localTestBytes = %ld\n", localTestBytes);
        printf("test_arr[] = %s ", source);
		printf("testOrig_arr1[] = %s\n", org_source);
        printf("========================\n");
        result = 0;
	}
	return (result);
}

int	ft_regular_teststrlcat(size_t testBytes)
{
	char test_arr[20] = "abqc";
	char test_arr1[20] = "01234567891";

	char testOrig_arr[20] = "abqc";
	char testOrig_arr1[20] = "01234567891";
	size_t localTestBytes = testBytes;

	int errorState = 1;
	size_t origRes = strlcat(testOrig_arr, testOrig_arr1, localTestBytes);
	size_t mineRes = ft_strlcat(test_arr, test_arr1, localTestBytes);

	if (origRes != mineRes)
	{
		printf("========================\n");
        printf("Error: test_ft_strlcat\n");
		printf("localTestBytes = %ld\n", localTestBytes);
		printf("strlcat() = %ld \n", origRes);
		printf("ft_strlcat() = %ld \n", mineRes);
		printf("testOrig_arr1[] = %s\n", testOrig_arr);
        printf("test_arr[] = %s\n", test_arr);

        printf("========================\n");
        errorState = 0;
	} else  if (strcmp(test_arr, testOrig_arr) != 0)
	{
		printf("========================\n");
        printf("Error: test_ft_strlcat\n");
		printf("localTestBytes = %ld\n", localTestBytes);
        printf("test_arr[] = %s ", test_arr);
		printf("testOrig_arr1[] = %s\n", testOrig_arr);
        printf("========================\n");
        errorState = 0;
	} else if (ft_test_same_arr() == 0) {
		errorState = 0;
	}
	return (errorState);
}

void test_ft_strlcat(void)
{

	int error = 1;
	size_t testBytes = 10;
	while (testBytes > 0)
	{
		if (ft_regular_teststrlcat(testBytes) == 0)
		{
			error = 0;
		}
		testBytes--;
	}
	if (error == 1) {
		printf("test_ft_strlcat: OK!\n");
	}
}