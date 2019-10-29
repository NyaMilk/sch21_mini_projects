/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:48:10 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/17 20:07:26 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr;

	i = 0;
	if (s && f)
	{
		if (!(ptr = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			ptr[i] = (*f)(s[i]);
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
