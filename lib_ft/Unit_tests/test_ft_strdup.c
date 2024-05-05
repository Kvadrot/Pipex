
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_strdup()
{
	char *origCoppy = "01234";
	char *testCopy = "01234";

	char *origResult = strdup(origCoppy);
	char *testResult = ft_strdup(testCopy);
	int errorState = 1;
	if (strcmp(origResult, testResult))
	{
		printf("========================\n");
        printf("Error: test_ft_strdup\n");
		printf("origResult[] = %s\n", origResult);
        printf("testResult[] = %s\n", testResult);
        printf("========================\n");
        errorState = 0;
	}

    if (errorState == 1)
    {
        printf("test_ft_strdup: OK!\n");
    }
}

// char	*ft_strdup(const char *s)
// {
// 	char	*newstr;
// 	char	*start;

// 	if (!s)
// 		return (NULL);
// 	newstr = (char *)malloc((ft_strlen(s) + 1) * sizeof(newstr));
// 	if (!newstr)
// 		return (NULL);
// 		start = newstr;
// 	while (*s)
// 	{
// 		printf(" %p ", &newstr);
// 		printf("testing1 %c", *s);
// 		*newstr++ = *s++;
// 		// newstr += 1;
// 		printf(" : %c \n", *s);
// 	}
// 	printf(" %p \n", &newstr);
// 	printf(" %p \n", &newstr[3]);
// 	printf(" %p \n", &newstr[2]);
// 	*newstr = '\0';
// 	newstr -= 5;
// 	return (newstr);
// }