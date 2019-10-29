/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:18:59 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/03 20:44:04 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

void			set_point(t_point *point);

#endif
