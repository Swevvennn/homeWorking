/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:12:46 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 17:14:04 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_check(char **map, t_square square, t_map_info map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((x <= square.x && square.x <= x + square.size - 1)
				&& (y <= square.y && square.y <= y + square.size - 1))
				;
		{
				if (map[y][x] == map_info.obstacle)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

struct s_square	ft_solver(char **map, t_map_info map_info)
{
	t_square	solution;
	t_square	current;

	current.size = 0;
	current.y = 0;
	while (current.y <= map_info.height - current.size + 1)
	{
		current.x = 0;
		while (current.x <= map_info.width[0] - current.size + 1)
		{
			while (ft_check(map, current, map_info) == 1)
			{
				solution.size = current.size;
				solution.x = current.x;
				solution.y = current.y;
				current.size++;
			}
			current.x++;
		}
		current.y++;
	}
	return (solution);
}

void	ft_fill_square(char **map, t_square square, t_map_info map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((x <= square.x && square.x <= x + square.size - 1)
				&& (y <= square.y && square.y <= y + square.size - 1))
				;
		{
				map[y][x] = map_info.full;
			}
			x++;
		}
		y++;
	}
}

void	ft_print_map(char **map, t_map_info map_info)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < map_info.height)
	{
		j = 0;
		while (j < map_info.width[1])
			write(1, &map[i][j++], 1);
		i++;
		write(1, "\n", 1);
	}
}

// int	main(void)
// {
// 	return (0);
// }
