/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:12:53 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/13 11:15:16 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char	res;

	res = (unsigned char)c;
	if (res < 32 || res > 126)
		return (0);
	return (1);
}
