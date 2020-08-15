/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:48:10 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 12:40:19 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr1;

	ptr1 = (unsigned char *)s;
	while (n > 0)
	{
		n--;
		if (*ptr1 == (unsigned char)c)
			return (ptr1);
		ptr1++;
	}
	return (NULL);
}
