/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:52:47 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/17 19:00:34 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *tmp;

	if (alst && *alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			tmp = ptr->next;
			(*del)(ptr->content, ptr->content_size);
			free(ptr);
			ptr = tmp;
		}
		*alst = NULL;
	}
}
