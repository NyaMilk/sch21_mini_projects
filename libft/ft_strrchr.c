/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:10:12 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/10 10:54:38 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	char			*ptr1;
	int				i;

	chr = (unsigned char)c;
	ptr1 = (char *)s;
	i = 0;
	while (ptr1[i])
		i++;
	while (ptr1[i] != chr && i >= 0)
		i--;
	if (i < 0)
		return (0);
	else
		return (ptr1 + i);
}
