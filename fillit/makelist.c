/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:39:24 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/23 19:21:40 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetr	*offset_tetr(t_tetr *lst)
{
	int			min_x;
	int			min_y;
	int			i;

	min_x = 3;
	min_y = 3;
	i = 0;
	while (i < 8)
	{
		if (lst->block[i] < min_x)
			min_x = lst->block[i];
		if (lst->block[i + 1] < min_y)
			min_y = lst->block[i + 1];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		lst->block[i] -= min_x;
		lst->block[i + 1] -= min_y;
		i += 2;
	}
	return (lst);
}

static t_tetr	*make_list(char *str, char letter)
{
	t_tetr		*lst;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 1;
	i = 0;
	if (!(lst = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	while (i < 19)
	{
		if (str[i] == '#')
		{
			lst->block[x] = i % 5;
			lst->block[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	lst->letter = letter;
	return (offset_tetr(lst));
}

t_tetr			*alphabetize(char *str, int size)
{
	t_tetr		*head;
	t_tetr		*lst;
	int			i;
	char		letter;

	i = 21;
	letter = 'A';
	head = make_list(str, letter);
	lst = head;
	while (i < size)
	{
		letter++;
		lst->next = make_list(str + i, letter);
		lst = lst->next;
		i += 21;
	}
	lst->next = NULL;
	return (head);
}
