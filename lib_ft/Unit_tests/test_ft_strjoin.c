
#include "../lib_ft/libft.h"
#include "libft_tests.h"


void	test_ft_strjoin()
{
	char *nullyStr = NULL;

	const char *arrStrPref[] = {
		"01234",
		"",
		"0123",
		nullyStr,
		"12",
		nullyStr
    };

    const char *arrStrSuff[] = {
		"56789s",
		"12321",
		"",
		"11",
		nullyStr,
		nullyStr
    };

	char	*defaultAnswer[] = {
		"0123456789s",
		"12321",
		"0123",
		"11",
		"12",
		""
	};

    int numCases = sizeof(arrStrPref) / sizeof(arrStrPref[0]);

    int errorState = 1;

    for (int i = 0; i < numCases; i++)
    {
        const char *mineResult = ft_strjoin(arrStrPref[i], arrStrSuff[i]);
		if (!mineResult 
			&& defaultAnswer[i])
		{
			printf("========================\n");
            printf("Error: test_ft_strjoin\n");
            printf("i = %d\n", i);
			printf("ft_strjoin returned Unexpected NULL");
            printf("========================\n");
		}
		if (!mineResult)
			continue;
        if (strcmp(mineResult, defaultAnswer[i]) != 0)
        {
            printf("========================\n");
            printf("Error: test_ft_strjoin\n");
            printf("i = %d\n", i);
			printf("strcmp = %d \n", strcmp(mineResult, arrStrSuff[i]));
            printf("ft_strjoin() = %s instaed of: %s\n", mineResult, defaultAnswer[i]);
            printf("========================\n");
            errorState = 0;
        }
    }

    if (errorState == 1)
    {
        printf("test_ft_strjoin: OK!\n");
    }
}