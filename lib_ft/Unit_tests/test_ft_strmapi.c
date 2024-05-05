
#include "../lib_ft/libft.h"
#include "libft_tests.h"


// Function to convert lowercase letters to uppercase
char to_upper(unsigned int index, char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A'; // Convert lowercase letters to uppercase
    }
	index++;
    return c; // Leave other characters unchanged
}

// Function to convert uppercase letters to lowercase
char to_lower(unsigned int index, char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a'; // Convert uppercase letters to lowercase
    }
	index++;
    return c; // Leave other characters unchanged
}

// Function to append a character to each character in the input string
char append_char(unsigned int index, char c) {
    // Assuming index is not used for this function
    (void)index;
    return c + 1; // Append the character with the next character in ASCII
}

void	test_ft_strmapi()
{
    int errorState = 1;

    // Array of test strings, function pointers, and expected results
    char *test_strings[] = {"hello", "abcde", "12345", "AaBbCcDdEe"};
    char (*test_functions[])(unsigned int, char) = {to_upper, to_upper, to_upper, append_char};
    char *expected_results[] = {"HELLO", "ABCDE", "12345", "BbCcDdEeFf"};

    // Iterate through test cases
    for (size_t i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++)
    {
        char *test_string = test_strings[i];
        char *expected_result = expected_results[i];

        // Run ft_strmapi
        char *result = ft_strmapi(test_string, test_functions[i]);

        // Compare result with expected result
        if (strcmp(result, expected_result) != 0)
        {
            printf("========================\n");
            printf("Error: test_ft_strmapi\n");
            printf("Test Case %zu: Expected: '%s', Actual: '%s'\n", i + 1, expected_result, result);
            printf("========================\n");
            errorState = 0;
        }

        // Free memory allocated by ft_strmapi
        free(result);
    }

    // Print final result
    if (errorState == 1)
    {
        printf("test_ft_strmapi: OK!\n");
    }
    else
    {
        printf("test_ft_strmapi: Error!\n");
    }
}