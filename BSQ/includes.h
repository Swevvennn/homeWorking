/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:53:03 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 16:13:33 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUF_SIZE 1

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

typedef struct s_map_info
{
	char	empty;
	char	obstacle;
	char	full;
	int		height;
	int		*width;
}	t_map_info;

t_map_info	ft_height(char *filename);
void		ft_tab_width(t_map_info *map_info, char *filename);
int			ft_check_width(t_map_info map_info);
char		**ft_map(t_map_info map_info, char *filename, char **map);

t_square	ft_solver(char **map, t_map_info map_info);
void		ft_fill_square(char **map, t_square square, t_map_info map_info);
void		ft_print_map(char **map, t_map_info map_info);

#endif