/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:21:04 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/13 10:38:12 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	unsigned char	res;

	res = (unsigned char)c;
	if (res < 'A' || (res > 'Z' && res < 'a') || res > 'z')
		return (0);
	return (1);
}
