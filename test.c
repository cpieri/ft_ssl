#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	(void)ac;
	printf("len: %zu\n", strlen(av[1]));
	return (0);
}
