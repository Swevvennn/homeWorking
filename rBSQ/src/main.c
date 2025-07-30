/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:07:43 by caaubert          #+#    #+#             */
/*   Updated: 2025/07/30 14:31:10 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_wait_input(void)
{
}

void	ft_treat_map(t_map *map, char **raw_map, t_map_info *map_info)
{
	map = ft_map_assign(raw_map);
	ft_fill_square(map, ft_solver(map, *map_info), *map_info);
	ft_print_map(map);
}

int	main(int argc, char **argv)
{
	char		**raw_map;
	t_map_info	*map_info;
	t_map		map;
	int			i;

	if (argc == 1)
	{
		ft_wait_input();
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_validity_checker(argv[i], &raw_map, &map_info))
				ft_treat_map(&map, raw_map, map_info);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
