/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:34:56 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 11:02:34 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	char			*ptr1;

	chr = (unsigned char)c;
	ptr1 = (char *)s;
	while (*ptr1)
	{
		if (*ptr1 == chr)
			return (ptr1);
		ptr1++;
	}
	if (chr == '\0')
		return (ptr1);
	return (0);
}
