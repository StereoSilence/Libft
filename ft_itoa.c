/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:22 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/22 15:35:22 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	buf[12];

	num = n;
	len = 11;
	buf[len--] = '\0';
	if (num == 0)
		buf[len--] = '0';
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		buf[len--] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		buf[len--] = '-';
	return (ft_strdup(&buf[len + 1]));
}
