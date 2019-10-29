/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:14:36 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/02 13:15:41 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*dupl;
	size_t	i;

	i = 0;
	if (!(dupl = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (s1[i] && n > i)
	{
		dupl[i] = s1[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}
