/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:13:26 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/23 16:31:45 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_char(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (str[i] != '\n')
		return (0);
	if (str[i + 1] != '\n' && str[i + 1] != '\0')
		return (0);
	return (count);
}

static int	check_block(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' && i + 1 < 19)
				count++;
			if (str[i - 1] == '#' && i - 1 >= 0)
				count++;
			if (str[i + 5] == '#' && i + 5 < 19)
				count++;
			if (str[i - 5] == '#' && i - 5 >= 0)
				count++;
		}
		i++;
	}
	return (count);
}

int			check_file(char *str, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (check_char(str + i) != 4)
			return (0);
		if (check_block(str + i) != 6 && check_block(str + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
