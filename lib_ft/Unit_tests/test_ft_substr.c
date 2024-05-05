
#include "../lib_ft/libft.h"
#include "libft_tests.h"

void	test_ft_substr()
{
	char	str[] = "lorem ipsum dolor sit amet";

	char *subStr = ft_substr(str, 0, 10);

	int errorState = 1;
	
	if (strcmp(subStr, "lorem ipsu") != 0)
	{
		printf("========================\n");
		printf("Error: test_ft_substr\n");
		printf("substr(0, 10) = %s instead lorem ipsu\n", subStr);
		printf("========================\n");
		errorState = 0;
	} 

	if (errorState == 1)
	{
		printf("test_ft_substr: OK!\n");
	}
}