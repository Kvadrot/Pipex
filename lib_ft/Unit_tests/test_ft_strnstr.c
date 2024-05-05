
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void test_ft_strnstr(void)
{
    const char *biStr[] = {
        "The quick brown fox jumps over the lazy dog",
        "AABAACAADAABAABA",
        "aaaa",
        "abcd",
        "abcd",
        "abcd",
        "abcd",
        "abddcd",
        "abcd",
        "abcd",
        "abcd",
        "abcd"
    };

    const char *littleStr[] = {
        "fox",
        "AABA",
        "aa",
        "efgh",
        "dcbdda",
        "abasdascd",
        "dd",
        "d",
        "dasd",
        "abcdx",
        "",
        "x"
    };

    size_t sizes[] = {
        43,
        14,
        4,
        1,
        2,
        1,
        4,
        0,
        3,
        66,
        4,
        4
    };

    int numCases = sizeof(biStr) / sizeof(biStr[0]);

    int errorState = 1;

    for (int i = 0; i < numCases; i++)
    {
        const char *origResult = strnstr(biStr[i], littleStr[i], sizes[i]);
        const char *mineResult = ft_strnstr(biStr[i], littleStr[i], sizes[i]);

        if (origResult != mineResult)
        {
            printf("========================\n");
            printf("Error: test_ft_strnstr\n");
            printf("i = %d\n", i);
            printf("strnstr() = %p \n", origResult);
            printf("ft_strnstr() = %p \n", mineResult);
            printf("========================\n");
            errorState = 0;
        }
    }

    if (errorState == 1)
    {
        printf("test_ft_strnstr: OK!\n");
    }
}

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	if (ft_strlen(little) == 0)
// 		return ((char *)big);
// 	while (big != NULL)
// 	{
// 		big = ft_strchr(big, little[0]);
// 		if (ft_strncmp(big, little, len) == 0)
// 			return ((char *)big);
// 		big++;
// 	}
// 	return (NULL);
// }