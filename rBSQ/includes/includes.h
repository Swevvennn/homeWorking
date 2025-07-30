/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:42:31 by mosmond          #+#    #+#             */
/*   Updated: 2025/07/29 17:12:02 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_square
{
	int	size;
	int	x;
	int	y;
}	t_square;

typedef struct s_map_info
{
	int		size;
	char	empty;
	char	obst;
	char	full;
}	t_map_info;

typedef struct s_map
{
	char	**map;
	int		line;
	int		col;
}	t_map;

struct s_map		*ft_map_assign(char **map);
struct s_square		ft_solver(t_map *map, t_map_info map_info);
void				ft_fill_square(t_map *map, t_square square,
						t_map_info map_info);
void				ft_print_map(t_map *map);
int					ft_validity_checker(char *file_name, char ***map,
						t_map_info **params);
int					ft_first_line_check(char *file_name, char **first_line);
struct s_map_info	*ft_param_filler(char *first_line);
int					ft_strlen(char *str);
int					ft_strict_atoi(char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_isolate_first_line(int fd);
char				*ft_strcpy(char *dest, char *src);
char				**ft_split(char *str, char *charset);
char				**ft_file(int file_open, unsigned long mapsize);
int					ft_map_equal(char **map, char obstacle, char void_indic);
void				ft_big_big_free(char **array);

#endif