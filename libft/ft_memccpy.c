/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:36:32 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 11:21:26 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		ptr1[i] = ptr2[i];
		if (ptr1[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
