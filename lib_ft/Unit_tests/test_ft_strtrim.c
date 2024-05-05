
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void test_ft_strtrim()
{
    int errorState = 1;

    // Array of test strings
    char *test_strings[] = {
        "  lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse  ",
        "  \t\napple,banana,orange\t\n ",
        "\t \tone:two:three   \t\t",
        "   \tThis is a test string \t\n"
        // Add more test strings here if needed
    };

    // Array of sets corresponding to test strings
    char *sets[] = {
        " ",
        " \t\n",
        " \t",
        " \t\n"
        // Add more sets here if needed
    };

    // Array of expected results corresponding to test strings
    char *expected_results[] = {
        "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse",
        "apple,banana,orange",
        "one:two:three",
        "This is a test string"
        // Add more expected results here if needed
    };

    // Iterate through test cases
    for (size_t i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++)
    {
        char *test_str = test_strings[i];
        char *set = sets[i];
        char *expected_result = expected_results[i];

        // Run ft_strtrim
        char *result = ft_strtrim(test_str, set);

        // Compare result with expected result
        if (strcmp(result, expected_result) != 0)
        {
            printf("========================\n");
            printf("Error: test_ft_strtrim\n");
            printf("Test Case %zu: Expected: '%s', Actual: '%s'\n", i + 1, expected_result, result);
            printf("========================\n");
            errorState = 0;
        }

        // Free memory allocated by ft_strtrim
        free(result);
    }

    if (errorState == 1)
    {
        printf("test_ft_strtrim: OK!\n");
    }
}
