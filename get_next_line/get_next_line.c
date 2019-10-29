/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:58:10 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/03 12:37:56 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*check_fd(t_list **head, int fd)
{
	t_list			*lst;

	lst = *head;
	while (lst)
	{
		if ((int)lst->content_size == fd)
			return (lst);
		lst = lst->next;
	}
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->content = ft_strnew(1);
	lst->content_size = fd;
	lst->next = NULL;
	ft_lstadd(head, lst);
	return (lst);
}

static int			copy_line(char **line, char *content, char c)
{
	int				end;

	end = 0;
	while (content[end] && content[end] != c)
		end++;
	if (!(*line = ft_strndup(content, end)))
		return (0);
	return (end);
}

static int			read_line(const int fd, char **content)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;
	char			*tmp;

	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (rd);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	size_t			rd;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, 0, 0)) < 0 ||
	(!(lst = check_fd(&head, fd))))
		return (-1);
	tmp = lst->content;
	rd = read_line(fd, &tmp);
	lst->content = tmp;
	if (!rd && !*tmp)
		return (0);
	rd = copy_line(line, lst->content, '\n');
	tmp = lst->content;
	if (tmp[rd])
	{
		lst->content = ft_strdup(lst->content + rd + 1);
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
