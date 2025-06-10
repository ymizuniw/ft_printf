// #include "include/ft_printf.h"
// #include <stdio.h>
// #include "ft_printf.h"

// int	main(void)
// {
// 	char	c;
// 	const char	*s;
// 	int		d;

// 	c = 'A';
// 	s = "fff";
// 	d = 15;
// 	// printf("%s\n", s);
// 	ft_printf("\n");
// 	return (0);
// }

// cc main.c src/*.c src/parse_args_utils_mnd/*.c libft/*.c

// //mandatory
// //C
// 	TEST(4, print("%c ", '0' + 256));
// 	TEST(5, print(" %c %c %c ", '0', 0, '1'));

// 	TEST(8, print(" %c %c %c ", '2', '1', 0));
// 	TEST(9, print(" %c %c %c ", 0, '1', '2'));
// //S
// 	TEST(3, print("%s ", ""));
// 	TEST(10, print(" NULL %s NULL ", NULL));

// //x
// 	TEST(24, print(" %x ", LONG_MAX));
// 	TEST(25, print(" %x ", LONG_MIN));
// 	TEST(26, print(" %x ", UINT_MAX));
// 	TEST(27, print(" %x ", ULONG_MAX));
// 	TEST(28, print(" %x ", 9223372036854775807LL));
// 	TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// //%
// 	TEST(4, print(" %%  %%  %% "));
// 	TEST(5, print(" %%   %%   %% "));
// 	TEST(7, print("%% %%"));

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int std_ret, ft_ret;

	int ret_ori, ret_my;
	int ori2, my2;
	int ori3, my3;

	ret_ori = printf("%c %c %c\n", '0', 0, '1');
	ret_my = ft_printf("%c %c %c\n", '0', 0, '1');

	printf("original: %i\n mine: %i\n", ret_ori, ret_my);

	ori2 = printf("%c %c %c\n", '2', '1', 0);
	my2 = ft_printf("%c %c %c\n", '2', '1', 0);

	printf("original: %i\n mine: %i\n", ori2, my2);


	// // %c
	// std_ret = printf("%c ", '0' + 256);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf("%c ", '0' + 256);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %c %c %c ", '0', 0, '1');
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %c %c %c ", '0', 0, '1');
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %c %c %c ", '2', '1', 0);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %c %c %c ", '2', '1', 0);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %c %c %c ", 0, '1', '2');
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %c %c %c ", 0, '1', '2');
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// // %s
	// std_ret = printf("%s ", "");
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf("%s ", "");
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" NULL %s NULL ", NULL);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" NULL %s NULL ", NULL);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// // %x
	// std_ret = printf(" %x ", (unsigned long)LONG_MAX);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %x ", (unsigned long)LONG_MAX);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %x ", (unsigned long)LONG_MIN);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %x ", (unsigned long)LONG_MIN);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %x ", UINT_MAX);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %x ", UINT_MAX);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %x ", (unsigned long)ULONG_MAX);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %x ", (unsigned long)ULONG_MAX);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %x ", (unsigned long long)9223372036854775807LL);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %x ", (unsigned long long)9223372036854775807LL);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %x %x %x %x %x %x %x",
	// 	INT_MAX, INT_MIN, (int)LONG_MAX, (int)LONG_MIN,
	// 	(int)ULONG_MAX, 0, -42);
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %x %x %x %x %x %x %x",
	// 	INT_MAX, INT_MIN, (int)LONG_MAX, (int)LONG_MIN,
	// 	(int)ULONG_MAX, 0, -42);
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// // %%
	// std_ret = printf(" %%  %%  %% ");
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %%  %%  %% ");
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf(" %%   %%   %% ");
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf(" %%   %%   %% ");
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	// std_ret = printf("%% %%");
	// printf("← printf ret = %d\n", std_ret);
	// ft_ret = ft_printf("%% %%");
	// printf("← ft_printf ret = %d\n\n", ft_ret);

	return (0);
}
