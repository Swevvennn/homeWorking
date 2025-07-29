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

#endif