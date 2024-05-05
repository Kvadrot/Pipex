
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void test_ft_memmove(void)
{
	char *dest_orig;
	char *dest_mine;
	char srcMine[] = "lorem ipsum dolor sit amet";
	char srcOrig[] = "lorem ipsum dolor sit amet";
	int testBytes = 5;
	// int moveByte = 2;

	int errorState = 1;

	dest_mine = srcMine + 1;
	dest_orig = srcOrig + 1;
	ft_memmove(dest_mine, srcMine, testBytes);
	memmove(dest_orig, srcOrig, testBytes);
	
	if (memcmp(dest_orig, dest_mine, testBytes) != 0)
	{
		printf("========================\n");
        printf("Error: test_ft_memmove\n");
		printf("memcmp(dest_orig, dest_mine, testBytes)  = %d \n", memcmp(dest_orig, dest_mine, testBytes));
        printf("dest_orig[] = %s\n dest_mine[] = %s\n", dest_orig, dest_mine);
        printf("========================\n");
        errorState = 0;
	}

	if (errorState == 1)
    {
        printf("test_ft_memmove: OK!\n");
    }

}