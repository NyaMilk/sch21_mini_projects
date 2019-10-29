/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:38:36 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/22 16:42:19 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error_out(void)
{
	ft_putendl("error");
	exit(1);
}

static	t_tetr	*read_file(char *s)
{
	int			fd;
	int			rd;
	char		buf[545];

	if ((fd = open(s, O_RDONLY)) < 0)
		error_out();
	if ((rd = read(fd, buf, 545)) < 0)
		error_out();
	if (rd > 545 || rd < 20)
		error_out();
	buf[rd] = '\0';
	close(fd);
	if (!check_file(buf, rd))
		error_out();
	return (alphabetize(buf, rd));
}

int				main(int ac, char **av)
{
	t_tetr		*tmp;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		exit(1);
	}
	if (!(tmp = read_file(av[1])))
		error_out();
	solve_file(tmp);
	free_list(tmp);
	return (0);
}
