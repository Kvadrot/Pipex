
#include "../lib_ft/libft.h"
#include "libft_tests.h"


void test_ft_itoa()
{
    int errorState = 1;

    // Array of test numbers and expected results
    int test_numbers[] = {0, 123456, -789, 2147483647, -2147483648};
    char *expected_results[] = {"0", "123456", "-789", "2147483647", "-2147483648"};

    // Iterate through test cases
    for (size_t i = 0; i < sizeof(test_numbers) / sizeof(test_numbers[0]); i++)
    {
        int test_num = test_numbers[i];
        char *expected_result = expected_results[i];

        // Run ft_itoa
        char *result = ft_itoa(test_num);

        // Compare result with expected result
        if (strcmp(result, expected_result) != 0)
        {
            printf("========================\n");
            printf("Error: test_ft_itoa\n");
            printf("Test Case %zu: Expected: '%s', Actual: '%s'\n", i + 1, expected_result, result);
            printf("========================\n");
            errorState = 0;
        }

        // Free memory allocated by ft_itoa
        free(result);
    }

    // Print final result
    if (errorState == 1)
    {
        printf("test_ft_itoa: OK!\n");
    }
    else
    {
        printf("test_ft_itoa: Error!\n");
    }
}