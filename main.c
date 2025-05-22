/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:04:13 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/22 13:55:52 by akorzhov         ###   ########.fr       */
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

// Helper for ft_lstdelone test
void del_func(void *content) {
    printf("del_func called for: %s\n", (char *)content);
    free(content);
}

// Helper for ft_lstiter test
void iter_func_lst(void *content) {
    char *s = (char *)content;
    s[0] += 1;
}

// Helper for ft_lstmap test
void *map_func_lst(void *content) {
    char *s = (char *)content;
    char *dup = strdup(s);
    if (dup && dup[0] >= 'a' && dup[0] <= 'z') dup[0] -= 32;
    return dup;
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

	printf("\n=== BONUS ===\n");

	printf("\n=== ft_lstnew ===\n");
	t_list *test = ft_lstnew("hello");
	printf("content: ft_lstnew('hello')%s\n", (char *)test->content);
	printf("next: %p\n", test->next);

	printf("\n=== ft_lstadd_front ===\n");
	t_list *new_node = ft_lstnew("world");
	ft_lstadd_front(&test, new_node);

	// Custom tests for ft_lstadd_front
	printf("\n=== ft_lstadd_front ===\n");
	// Create three nodes
	t_list *head = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");
	t_list *node3 = ft_lstnew("third");
	// Add node2 to front
	ft_lstadd_front(&head, node2);
	// Add node3 to front
	ft_lstadd_front(&head, node3);
	// Print list contents
	t_list *cur = head;
	int idx = 0;
	while (cur) {
	    printf("Node %d: %s\n", idx++, (char *)cur->content);
	    cur = cur->next;
	}
	// Free list
	t_list *tmp;
	cur = head;
	while (cur) {
	    tmp = cur->next;
	    free(cur);
	    cur = tmp;
	}

	printf("\n=== ft_lstsize & ft_lstadd_back ===\n");
	t_list *size_head = ft_lstnew("one");
	ft_lstadd_back(&size_head, ft_lstnew("two"));
	ft_lstadd_back(&size_head, ft_lstnew("three"));
	int size = ft_lstsize(size_head);
	printf("List size (should be 3): %d\n", size);
	// Free list
	t_list *tmp2;
	t_list *cur2 = size_head;
	while (cur2) {
	    tmp2 = cur2->next;
	    free(cur2);
	    cur2 = tmp2;
	}

	printf("\n=== ft_lstlast ===\n");
	t_list *last_head = ft_lstnew("alpha");
	ft_lstadd_back(&last_head, ft_lstnew("beta"));
	ft_lstadd_back(&last_head, ft_lstnew("gamma"));
	t_list *last = ft_lstlast(last_head);
	if (last)
	    printf("Last node content (should be 'gamma'): %s\n", (char *)last->content);
	else
	    printf("List is empty!\n");
	// Free list
	t_list *tmp3;
	t_list *cur3 = last_head;
	while (cur3) {
	    tmp3 = cur3->next;
	    free(cur3);
	    cur3 = tmp3;
	}

	printf("\n=== ft_lstdelone ===\n");
	t_list *del_node = ft_lstnew(ft_strdup("to be deleted"));
	printf("Before del: %s\n", (char *)del_node->content);
	ft_lstdelone(del_node, del_func);
	printf("Node deleted (should not print content)\n");

	printf("\n=== ft_lstclear ===\n");
	t_list *clear_head = ft_lstnew(ft_strdup("node1"));
	ft_lstadd_back(&clear_head, ft_lstnew(ft_strdup("node2")));
	ft_lstadd_back(&clear_head, ft_lstnew(ft_strdup("node3")));
	printf("Before clear, first node: %s\n", (char *)clear_head->content);
	ft_lstclear(&clear_head, del_func);
	if (clear_head == NULL)
	    printf("List cleared (head is NULL)\n");
	else
	    printf("List not cleared!\n");

	printf("\n=== ft_lstiter ===\n");
	t_list *iter_head = ft_lstnew(ft_strdup("A"));
	ft_lstadd_back(&iter_head, ft_lstnew(ft_strdup("B")));
	ft_lstadd_back(&iter_head, ft_lstnew(ft_strdup("C")));
	printf("Before iter: %s, %s, %s\n", (char *)iter_head->content, (char *)iter_head->next->content, (char *)iter_head->next->next->content);
	ft_lstiter(iter_head, iter_func_lst);
	printf("After iter: %s, %s, %s\n", (char *)iter_head->content, (char *)iter_head->next->content, (char *)iter_head->next->next->content);
	ft_lstclear(&iter_head, del_func);

	printf("\n=== ft_lstmap ===\n");
	t_list *map_head = ft_lstnew(ft_strdup("foo"));
	ft_lstadd_back(&map_head, ft_lstnew(ft_strdup("bar")));
	ft_lstadd_back(&map_head, ft_lstnew(ft_strdup("baz")));
	t_list *mapped_list = ft_lstmap(map_head, map_func_lst, del_func);
	if (mapped_list && mapped_list->next && mapped_list->next->next)
        printf("Mapped list: %s, %s, %s\n", (char *)mapped_list->content, (char *)mapped_list->next->content, (char *)mapped_list->next->next->content);
    else
        printf("Mapped list is incomplete or NULL!\n");
    ft_lstclear(&map_head, del_func);
    ft_lstclear(&mapped_list, del_func);

	return (0);
}
