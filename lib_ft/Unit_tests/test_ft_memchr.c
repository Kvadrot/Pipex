
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_memchr()
{
	char testArr[20] = "0123456789";
	int searchChar = 128;
	size_t maxSize = 4;
	int errorState = 1;

	for (size_t size = 0; size < maxSize; size++)
	{

		char *origResult = memchr(testArr, searchChar, size);
		char *mineResult = ft_memchr(testArr, searchChar, size);

		if (origResult != mineResult)
		{
			printf("========================\n");
			printf("Error: test_ft_memchr\n");
			printf("memchr() = %p but ft_memchr() = %p\n", origResult, mineResult);
			printf("========================\n");
			errorState = 0;
		}
	}
	if (errorState == 1)
	{
		printf("test_ft_memchr: OK!\n");
	}
}