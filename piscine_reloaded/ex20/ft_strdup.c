/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:19:53 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/03 17:10:51 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *dupl;

	dupl = (char *)malloc(sizeof(src));
	if (dupl != NULL)
		ft_strcpy(dupl, src);
	return (dupl);
}
