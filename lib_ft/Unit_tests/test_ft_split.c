
#include "../lib_ft/libft.h"
#include "libft_tests.h"

#include <stdio.h>

void test_ft_split()
{
    int errorState = 1;

    // Array of test strings
    char *test_strings[] = {
        " lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse",
        "apple,banana,orange ",
        "one:two:three",
        " This is a test string ",
		""
        // Add more test strings here if needed
    };

    // Array of delimiters corresponding to test strings
    char delimiters[] = {' ', 
						',', 
						':', 
						' ',
						' '};

    // Array of expected results corresponding to test strings
    char *expected_results[][13] = {
        {"lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit.", "Sed", "non", "risus.", "Suspendisse", NULL},
        {"apple", "banana", "orange ", NULL},
        {"one", "two", "three", NULL},
        {"This", "is", "a", "test", "string", NULL},
		{NULL}
        // Add more expected results here if needed
    };

    // Iterate through test cases
    for (size_t i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++)
    {
        char *test_str = test_strings[i];
        char delimiter = delimiters[i];
        char **expected_result = expected_results[i];

        // Run ft_split
        char **result = ft_split(test_str, delimiter);

        // Compare result with expected result
        for (size_t j = 0; expected_result[j] != NULL || result[j] != NULL; j++)
        {
            if (expected_result[j] == NULL || result[j] == NULL || strcmp(expected_result[j], result[j]) != 0)
            {
                printf("========================\n");
                printf("Error: test_ft_split\n");
                printf("Test Case %zu: Error at index %zu\n", i, j);
				printf("Expected: %s\n", expected_result[j]);
                printf("Actual: %s\n", result[j]);
                printf("========================\n");
                errorState = 0;
                break;
            }
        }

        // Free memory allocated by ft_split
        for (size_t j = 0; result[j] != NULL; j++)
        {
            free(result[j]);
        }
        free(result);
    }

    if (errorState == 1)
    {
        printf("test_ft_split: OK!\n");
    }
}
