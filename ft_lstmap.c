/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:53:04 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/21 16:15:39 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_node;
	void	*tmp;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = f(lst -> content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			ft_lstclear(&res, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&res, new_node);
		lst = lst -> next;
	}
	return (res);
}
