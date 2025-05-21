/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:21:18 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/21 11:13:40 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		s_len;
	int		i;

	s_len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * (s_len + 1));
	if (res == NULL)
		return (NULL);
	while (i < s_len)
	{
		res[i] = s[i];
		i++;
	}
	res[s_len] = '\0';
	return (res);
}
