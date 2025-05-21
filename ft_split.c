/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:26:13 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/21 11:13:28 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	res;
	int	in_word;

	res = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			res += 1;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (res);
}

static char	*ft_copy_word(char const *s, size_t len)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	free_all(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

static int	split_fill_word(char **result, int i, char const **s, char c)
{
	size_t		len;
	char const	*start;

	while (**s == c)
		(*s)++;
	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		len++;
		(*s)++;
	}
	result[i] = ft_copy_word(start, len);
	if (!result[i])
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		if (!split_fill_word(result, i, &s, c))
		{
			free_all(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
