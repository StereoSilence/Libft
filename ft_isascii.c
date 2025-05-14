/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:02:52 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/13 11:09:16 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(char c)
{
	unsigned char	res;

	res = (unsigned char)c;
	if (res >= 0 && res <= 127)
		return (1);
	return (0);
}
