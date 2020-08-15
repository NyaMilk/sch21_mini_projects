/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:22:33 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/18 17:23:42 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_calspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	int			i;
	int			start;
	int			end;
	char		*tmp;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	while (s[start] && ft_calspace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (s[end] && ft_calspace(s[end]))
		end--;
	if (end < 0)
		return (ft_memalloc(1));
	if (!(tmp = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start <= end)
	{
		tmp[i++] = s[start];
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}
