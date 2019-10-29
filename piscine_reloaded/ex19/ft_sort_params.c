/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:11:13 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/04 12:45:17 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_print_params(int ac, char **av)
{
	int i;
	int c;

	i = 0;
	c = 1;
	while (c < ac)
	{
		while (av[c][i])
		{
			ft_putchar(av[c][i]);
			i++;
		}
		c++;
		i = 0;
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac - 1)
	{
		if (i + 1 < ac && ft_strcmp(av[i + 1], av[i]) < 0)
		{
			av[ac + 1] = av[i];
			av[i] = av[i + 1];
			av[i + 1] = av[ac + 1];
			i = 0;
		}
		i++;
	}
	ft_print_params(ac, av);
	return (0);
}
