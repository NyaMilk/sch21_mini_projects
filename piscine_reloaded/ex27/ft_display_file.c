/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:29:53 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/04 14:36:41 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = 0;
	if (ac < 2)
		write(2, "File name missing.\n", 19);
	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	if (fd)
	{
		while ((ret = read(fd, buf, 1)))
			write(1, &buf, 1);
	}
	close(fd);
	return (0);
}
