/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:12:24 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/19 18:38:38 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	res;

	res = n;
	if (res < 0)
	{
		write(fd, "-", 1);
		res *= -1;
	}
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	write(fd, &"0123456789"[res % 10], 1);
}
