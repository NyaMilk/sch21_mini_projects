/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:45:03 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 11:57:52 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst)
		return (NULL);
	list = (*f)(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = (*f)(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
