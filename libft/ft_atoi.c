/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:11:22 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/18 14:44:38 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_maxmin(unsigned long long int res, long long int negative)
{
	if (res > 9223372036854775807 && negative == 1)
		return (-1);
	if (res > 9223372036854775807 && negative == -1)
		return (0);
	return (res * negative);
}

int				ft_atoi(const char *str)
{
	long long int	nb;
	long long int	negative;
	int				i;

	nb = 0;
	negative = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (ft_maxmin(nb, negative));
}
