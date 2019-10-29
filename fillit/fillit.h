/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:58:35 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/22 16:50:07 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct		s_tetr
{
	int				block[8];
	int				offset_x;
	int				offset_y;
	char			letter;
	struct s_tetr	*next;
}					t_tetr;

void				error_out(void);
void				free_list(t_tetr *lst);
void				print_map(char **map, int map_size);
void				free_map(char **map, int map_size);
void				solve_file(t_tetr *head);
t_tetr				*alphabetize(char *str, int size);
int					check_file(char *str, int size);
int					count_tetr(t_tetr *list);
int					min_size(int count);

#endif
