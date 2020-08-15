/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:36:12 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/18 19:26:50 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cword(char const *s, char c)
{
	int			word;
	int			number_words;
	int			i;

	word = 0;
	number_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			number_words++;
			word = 1;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (number_words);
}

static int		ft_clen(char const *s, char c)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		*ft_sncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len && dst[i])
	{
		dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	int			word;
	int			n;

	if (!s || (!(arr = (char **)malloc(sizeof(char *) * ft_cword(s, c) + 1))))
		return (NULL);
	word = 0;
	n = 0;
	while (*s)
	{
		if (*s != c && *s && word == 0)
		{
			word = 1;
			if (!(arr[n] = (char *)malloc(sizeof(char) * ft_clen(&*s, c) + 1)))
				return (NULL);
			arr[n] = ft_sncpy(arr[n], &*s, ft_clen(&*s, c));
			n++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	arr[n] = NULL;
	return (arr);
}
