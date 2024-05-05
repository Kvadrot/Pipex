

#include "../lib_ft/libft.h"
#include "libft_tests.h"

static void	ft_small_func(unsigned int ind, char *c)
{
	*c = ft_toupper((int)*c);
	(void)ind; // Unused parameter
}

void	test_ft_striteri()
{
	char test[] = "abcd";
	char answer[] = "ABCD";
	ft_striteri(test, ft_small_func);

	if (strcmp(test, answer) == 0)
		printf("test_ft_striteri: OK!\n");
	else
		printf("test_ft_striteri: Error!\n");
}
