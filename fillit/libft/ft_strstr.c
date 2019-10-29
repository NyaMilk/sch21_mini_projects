/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:08:58 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 10:45:55 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr1;
	char	*ptr2;
	int		i;
	int		j;

	ptr1 = (char *)haystack;
	ptr2 = (char *)needle;
	i = 0;
	j = 0;
	if (ptr2[0] == 0)
		return (&ptr1[i]);
	while (ptr1[i])
	{
		while ((ptr1[i + j] == ptr2[j]) && ptr2[j])
		{
			j++;
			if (ptr2[j] == 0)
				return (&ptr1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
