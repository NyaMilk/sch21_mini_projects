/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:11:16 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 10:46:41 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;
	size_t	j;

	ptr1 = (char *)haystack;
	ptr2 = (char *)needle;
	i = 0;
	j = 0;
	if (ptr2[0] == 0)
		return (&ptr1[i]);
	while (ptr1[i] && i < len)
	{
		while ((ptr1[i + j] == ptr2[j]) && ptr2[j] && (i + j) < len)
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
