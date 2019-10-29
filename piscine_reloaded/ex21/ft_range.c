/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:13:05 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/04 20:38:41 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int i;

	i = 0;
	if (min < max)
	{
		arr = (int *)malloc(sizeof(int) * (max - min));
		while (min < max)
		{
			arr[i] = min;
			i++;
			min++;
		}
		return (arr);
	}
	return (0);
}
