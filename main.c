/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:39:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 01:04:18 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

// int	main(void)
// {
// 	int	n;
// 	int	m;

// 	n = ft_printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
// 	m = printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
// 	// ft_printf("%#x", 42);
// 	printf("%d\n", n);
// 	printf("%d\n", m);
// 	ft_printf("%%%%\n");
// 	printf("%%%%\n");
// 	ft_printf("\n");
// 	printf("\n");
// 	return (0);
// }

int	main(void)
{
	// int	ret1, ret2;
	// char	c = 'A';
	// char	*str = "42Tokyo";
	// char	*null_str = NULL;
	// int		num = -1234;
	// int		pos_num = 5678;
	// unsigned int uval = UINT_MAX;

	ft_printf("%d\n", INT_MIN);   // → -2147483648
	printf("%d\n", INT_MIN);

	

	// === %d, %i ===
	// ft_printf("%d\n", 0);         // → 0
	// printf("%d\n", 0);

	// ft_printf("%d\n", 1);         // → 1
	// printf("%d\n", 1);

	// ft_printf("%d\n", -1);        // → -1
	// printf("%d\n", -1);

	// ft_printf("%d\n", INT_MAX);   // → 2147483647
	// printf("%d\n", INT_MAX);

	// ft_printf("%d\n", INT_MIN);   // → -2147483648
	// printf("%d\n", INT_MIN);

	// ft_printf("% d\n", 42);       // → " 42"
	// printf("% d\n", 42);

	// ft_printf("%+d\n", 42);       // → "+42"
	// printf("%+d\n", 42);

	// ft_printf("%10d\n", 42);      // → "        42"
	// printf("%10d\n", 42);

	// ft_printf("%010d\n", 42);     // → "0000000042"
	// printf("%010d\n", 42);

	// ft_printf("%-10d\n", 42);     // → "42        "
	// printf("%-10d\n", 42);

	// ft_printf("%+010d\n", -42);   // → "-000000042"
	// printf("%+010d\n", -42);

	// // === %u ===
	// ft_printf("%u\n", 0);         // → 0
	// printf("%u\n", 0);

	// ft_printf("%u\n", UINT_MAX);  // → 4294967295
	// printf("%u\n", UINT_MAX);

	// ft_printf("%u\n", -1);        // → 4294967295（暗黙キャスト）
	// printf("%u\n", -1);

	// ft_printf("%10u\n", 123);     // → "       123"
	// printf("%10u\n", 123);

	// ft_printf("%010u\n", 123);    // → "0000000123"
	// printf("%010u\n", 123);

	// // === %x, %X ===
	// ft_printf("%x\n", 0);         // → "0"
	// printf("%x\n", 0);

	// ft_printf("%x\n", 42);        // → "2a"
	// printf("%x\n", 42);

	// ft_printf("%x\n", UINT_MAX);  // → "ffffffff"
	// printf("%x\n", UINT_MAX);

	// ft_printf("%#x\n", 42);       // → "0x2a"
	// printf("%#x\n", 42);

	// ft_printf("%X\n", 42);        // → "2A"
	// printf("%X\n", 42);

	// ft_printf("%#X\n", 42);       // → "0X2A"
	// printf("%#X\n", 42);

	// ft_printf("%#x\n", 0);        // → "0"（0のとき接頭辞なし）
	// printf("%#x\n", 0);

	// // === %c ===
	// ft_printf("%c\n", 'A');       // → "A"
	// printf("%c\n", 'A');

	// ft_printf("%c\n", 0);         // → 表示なし（NULL文字）
	// printf("%c\n", 0);

	// ft_printf("%5c\n", 'Z');      // → "    Z"
	// printf("%5c\n", 'Z');

	// // === %s ===
	// ft_printf("%s\n", "hello");       // → "hello"
	// printf("%s\n", "hello");

	// ft_printf("%s\n", "");            // → ""
	// printf("%s\n", "");

	// ft_printf("%.0s\n", "nonempty");  // → ""
	// printf("%.0s\n", "nonempty");

	// ft_printf("%.3s\n", "abcdef");    // → "abc"
	// printf("%.3s\n", "abcdef");

	// ft_printf("%10.3s\n", "abcdef");  // → "       abc"
	// printf("%10.3s\n", "abcdef");

	// // ft_printf("%s\n", NULL);          // → "(null)"（実装による）
	// // printf("%s\n", NULL);

	// // === %% ===
	// ft_printf("%%\n");            // → "%"
	// printf("%%\n");

	// ft_printf("%%%d%%\n", 42);    // → "%42%"
	// printf("%%%d%%\n", 42);

	// // === フラグ組み合わせ ===
	// ft_printf("%+ d\n", 42);      // → "+42"
	// printf("%+ d\n", 42);

	// ft_printf("%-+10d\n", 123);   // → "+123      "
	// printf("%-+10d\n", 123);

	// ft_printf("%0-10d\n", 123);   // → "123       "（"-"優先）
	// printf("%0-10d\n", 123);

	// ft_printf("%#08x\n", 42);     // → "0x00002a"
	// printf("%#08x\n", 42);

	// // === *（可変幅・精度）===
	// ft_printf("%*d\n", 5, 42);         // → "   42"
	// printf("%*d\n", 5, 42);

	// ft_printf("%.*s\n", 3, "abcdef");  // → "abc"
	// printf("%.*s\n", 3, "abcdef");

	// ft_printf("%*.*d\n", 8, 4, 42);    // → "    0042"
	// printf("%*.*d\n", 8, 4, 42);

	// ft_printf("%*.*x\n", 10, 5, 42);   // → "     0002a"
	// printf("%*.*x\n", 10, 5, 42);

	// // === 複合 ===
	// ft_printf("char: %c, str: %s, dec: %d, hex: %#x\n", 'A', "test", -42, 255);
	// // → "char: A, str: test, dec: -42, hex: 0xff"
	// printf("char: %c, str: %s, dec: %d, hex: %#x\n", 'A', "test", -42, 255);

	// ft_printf("混在: %d %x %s %% %c\n", 123, 0xabc, "abc", '!');
	// // → "混在: 123 abc abc % !"
	// printf("混在: %d %x %s %% %c\n", 123, 0xabc, "abc", '!');

	// // === 未定義動作例 ===
	// ft_printf("%d\n", 2147483648); // ⚠️ UB：int範囲外 → 結果は未定義
	// printf("%d\n", 2147483648); // ⚠️ 実行環境によっては警告または未定義

	// ft_printf("%s\n", (char *)NULL); // → "(null)" を想定（ft_printfの実装次第）
	// // printf("%s\n", (char *)NULL);    // → "(null)"（glibc）



// 	int i = 100;
// 	while (i-- > 0)
// {
// 	//--- CHAR ---
// 	ret1 = ft_printf("c: [%5c] [%-5c]\n", c, c);
// 	ret2 = printf("c: [%5c] [%-5c]\n", c, c);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	//--- STRING ---
// 	ret1 = ft_printf("s: [%10.3s] [%-10.4s] [%s] [%s]\n", str, str, "", null_str);
// 	ret2 = printf("s: [%10.3s] [%-10.4s] [%s] [%s]\n", str, str, "", null_str);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	//--- DECIMAL / INTEGER ---
// 	ret1 = ft_printf("d: [%10.5d] [% 10.5d] [%010d] [%-10d]\n", num, pos_num, num, pos_num);
// 	ret2 = printf("d: [%10.5d] [% 10.5d] [%010d] [%-10d]\n", num, pos_num, num, pos_num);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("i: [%+5.3i] [%-5.3i]\n", num, pos_num);
// 	ret2 = printf("i: [%+5.3i] [%-5.3i]\n", num, pos_num);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	// --- UNSIGNED ---
// 	ret1 = ft_printf("u: [%10u] [%-10.8u] [%08u]\n", uval, 42, 0);
// 	ret2 = printf("u: [%10u] [%-10.8u] [%08u]\n", uval, 42, 0);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	// --- HEXADECIMAL (lowercase) ---
// 	ret1 = ft_printf("x: [%#10x] [%#08x] [%#-10.4x]\n", 42, 0, 0x2a);
// 	ret2 = printf("x: [%#10x] [%#08x] [%#-10.4x]\n", 42, 0, 0x2a);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	// --- HEXADECIMAL (uppercase) ---
// 	ret1 = ft_printf("X: [%#10X] [%#08X] [%#-10.4X]\n", 42, 0, 0x2a);
// 	ret2 = printf("X: [%#10X] [%#08X] [%#-10.4X]\n", 42, 0, 0x2a);
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// 	// --- PERCENT ---
// 	ret1 = ft_printf("percent: [%%] [%%10] [%-5%]\n");
// 	ret2 = printf("percent: [%%] [%%10] [%-5%]\n");
// 	printf("ret: %d == %d\n\n", ret1, ret2);

// }
	return (0);
}
