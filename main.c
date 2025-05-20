/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:04:13 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/20 12:32:29 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	map_func(unsigned int i, char c)
{
    if (i % 2 == 0)
        return c;
    else
        return '*';
}

void	iter_func(unsigned int i, char *c)
{
	if (i % 2) *c = '_';
}

int	main(void)
{
	printf("=== Testing ft_isalpha ===\n");
	printf("A - %d\n", ft_isalpha('A'));
	printf("z - %d\n", ft_isalpha('z'));
	printf("5 - %d\n", ft_isalpha('5'));
	printf("$ - %d\n", ft_isalpha('$'));
	printf("0 - %d\n", ft_isalpha(0));

	printf("\n=== Testing ft_isdigit ===\n");
	printf("0 - %d\n", ft_isdigit('0'));
	printf("9 - %d\n", ft_isdigit('9'));
	printf("a - %d\n", ft_isdigit('a'));

	printf("\n=== Testing ft_isalnum ===\n");
	printf("a - %d\n", ft_isalnum('a'));
	printf("7 - %d\n", ft_isalnum('7'));
	printf("@ - %d\n", ft_isalnum('@'));

	printf("\n=== Testing ft_isascii ===\n");
	printf("A - %d\n", ft_isascii('A'));
	printf("200 - %d\n", ft_isascii(200));

	printf("\n=== Testing ft_isprint ===\n");
	printf("Space - %d\n", ft_isprint(' '));
	printf("DEL (127) - %d\n", ft_isprint(127));

	printf("\n=== Testing ft_tolower ===\n");
	printf("ft_tolower('H') - %d\n", ft_tolower('H'));

	printf("\n=== Testing ft_toupper ===\n");
	printf("ft_toupper('h') - %d\n", ft_toupper('h'));

	printf("\n=== ft_strlen / ft_strdup ===\n");
	printf("ft_strlen('Hello') = %zu\n", ft_strlen("Hello"));
	char *dup = ft_strdup("Test");
	printf("ft_strdup('Test') = %s\n", dup);
	free(dup);

	printf("\n=== ft_memset ===\n");
	char buffer[10];
	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("ft_memset(buffer, 'A', 5): %s\n", buffer);

	printf("\n=== ft_bzero ===\n");
	char zero[5] = "1234";
	ft_bzero(zero, 4);
	write(1, "ft_bzero(zero, 4): ", 22);
	write(1, zero, 4);
	write(1, "\n", 1);

	printf("\n=== ft_memcpy ===\n");
	char src[] = "abcde";
	char dest[10];
	ft_memcpy(dest, src, 5);
	dest[5] = '\0';
	printf("ft_memcpy(dest[10], abcde): %s\n", dest);

	printf("\n=== ft_memmove ===\n");
	char move[] = "123456789";
	ft_memmove(move + 2, move, 5);
	printf("ft_memmove overlap('123456789' + 2, '123456789', 5): %s\n", move);

	printf("\n=== ft_strchr ===\n");
	printf("ft_strchr('Hello 42', 'l') - %s\n", ft_strchr("Hello 42", 'l'));

	printf("\n=== ft_strrchr ===\n");
	printf("ft_strrchr('Hello 42 world', 'l') - %s\n", ft_strrchr("Hello 42 world", 'l'));

	printf("\n=== ft_strncmp ===\n");
	printf("ft_strncmp('Hello', 'Hey 42', 3) - %d\n", ft_strncmp("Hello", "Hey 42", 3));

	printf("\n=== ft_memchr ===\n");
	printf("ft_memchr('Hello 42', 'l', 5) - %s\n", (char *)ft_memchr("Hello 42", 'l', 5));

	printf("\n=== ft_memcmp ===\n");
	printf("ft_memcmp('Hello', 'Hellp', 4) - %d\n", ft_memcmp("Hello", "Hellp", 4));

	printf("\n=== ft_strnstr ===\n");
	char *haystack = "42 school is great";
	char *needle = "school";
	printf("ft_strnstr(haystack, needle, 18): %s\n", ft_strnstr(haystack, needle, 18));

	printf("\n=== ft_strlcpy ===\n");
	char copy[10];
	size_t len_cpy = ft_strlcpy(copy, "Hello", 10);
	printf("ft_strlcpy(copy, 'Hello', 10): %s (len: %zu)\n", copy, len_cpy);

	printf("\n=== ft_strlcat ===\n");
	char dst[20] = "42 ";
	size_t len_cat = ft_strlcat(dst, "Network", 20);
	printf("ft_strlcat('42 [20]', 'Network', 20): %s (len: %zu)\n", dst, len_cat);

	printf("\n=== ft_atoi ===\n");
	printf("ft_atoi('-42') = %d\n", ft_atoi("-42"));
	printf("ft_atoi('  +123abc') = %d\n", ft_atoi("  +123abc"));

	printf("\n=== ft_calloc ===\n");
	char *c = ft_calloc(5, sizeof(char));
	if (c)
	{
		printf("ft_calloc(5, sizeof(char)): allocated\n");
		free(c);
	}

	printf("\n=== ft_put* ===\n");
	ft_putchar_fd('X', 1);
	write(1, "\n", 1);
	ft_putstr_fd("Hello, 42\n", 1);
	ft_putendl_fd("This ends with newline", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);

	printf("\n=== ft_substr / ft_strjoin / ft_strtrim ===\n");
	char *sub = ft_substr("Hello World", 6, 5);
	printf("ft_substr('Hello World', 6, 5): %s\n", sub);
	free(sub);

	char *join = ft_strjoin("Hello", "42");
	printf("ft_strjoin('Hello', '42'): %s\n", join);
	free(join);

	char *trim = ft_strtrim("--hello--", "-");
	printf("ft_strtrim('--hello--', '-'):%s\n", trim);
	free(trim);

	printf("\n=== ft_split ===\n");
	char **split = ft_split("split this string", ' ');
	if (split)
	{
		for (int i = 0; split[i]; i++)
		{
			printf("split[%d]: %s\n", i, split[i]);
			free(split[i]);
		}
		free(split);
	}

	printf("\n=== ft_strmapi / ft_striteri ===\n");
	char *mapped = ft_strmapi("abcdef", map_func);
	printf("ft_strmapi('abcdef'): %s\n", mapped);
	free(mapped);

	char str2[] = "abcdef";
	ft_striteri(str2, iter_func);
	printf("ft_striteri('abcdef'): %s\n", str2);

	printf("\n=== ft_itoa ===\n");
	char *itoa_str = ft_itoa(-12345);
	printf("ft_itoa(-12345): %s\n", itoa_str);
	free(itoa_str);

	return (0);
}
