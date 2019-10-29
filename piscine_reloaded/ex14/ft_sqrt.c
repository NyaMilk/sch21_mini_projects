/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:06:15 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/04 12:16:24 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int sum;

	i = 1;
	sum = i * i;
	while (sum < nb)
	{
		i++;
		sum = i * i;
	}
	if (sum == nb)
		return (i);
	else
		return (0);
}
