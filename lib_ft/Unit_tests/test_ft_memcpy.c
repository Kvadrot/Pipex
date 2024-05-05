
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_memcpy()
{
	char arr_char[] = "0123456789";
	char orig_dest_char[10];
	char mine_dest_char[10];
	int errorState = 1;

	memcpy(orig_dest_char, arr_char, sizeof(orig_dest_char));
	ft_memcpy(mine_dest_char, arr_char, sizeof(mine_dest_char));

	if (memcmp(orig_dest_char, mine_dest_char, 10) != 0)
	{
		printf("========================\n");
		printf("Error: ft_memcpy_test\n");
		printf("tes_ft_memcpy() = %s but ft_memcpy() = %s\n", orig_dest_char, mine_dest_char);
		printf("========================\n");
		errorState = 0;
	}

	if (errorState == 1)
	{
		printf("test_ft_memcpy: OK!\n");
	}
}