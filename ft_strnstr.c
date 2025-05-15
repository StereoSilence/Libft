/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:45:33 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/15 10:23:17 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = 0;
	while (little[little_len])
		little_len++;
	while (*big && len > little_len)
	{
		i = 0;
		while (big[i] && little[i] && big[i] == little[i] && i < len)
			i++;
		if (!little[i])
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
