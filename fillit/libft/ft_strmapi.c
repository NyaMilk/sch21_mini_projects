/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:48:46 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/19 10:42:39 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (s && f)
	{
		if (!(ptr = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			ptr[i] = (*f)(i, s[i]);
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
