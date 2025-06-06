#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char c = 'A';
	char *s = "fff";
	int d = 15;
	ft_printf("%c\n, %s\n, %d\n", c, s, d);
	return (0);
}
