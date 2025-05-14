/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:47:23 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/14 11:08:01 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_uc;
	const unsigned char	*src_uc;

	dest_uc = (unsigned char *)dest;
	src_uc = (const unsigned char *)src;
	while (n > 0)
	{
		*dest_uc = *src_uc;
		dest_uc++;
		src_uc++;
		n--;
	}
	return (dest);
}
