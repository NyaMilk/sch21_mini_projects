/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:48:39 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/13 14:55:30 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dupl;

	dupl = (char *)malloc(sizeof(char) + ft_strlen(s1));
	if (dupl != NULL)
		ft_strcpy(dupl, s1);
	return (dupl);
}
