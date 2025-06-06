#include "include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char	*s;
	int		d;

	c = 'A';
	s = "fff";
	d = 15;
	// printf("function started\n this is (ex) %s", s);
	ft_printf("%s", s);
	return (0);
}
