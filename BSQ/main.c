/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:07:43 by caaubert          #+#    #+#             */
/*   Updated: 2025/07/29 16:13:34 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_follow_main(char **map, t_map_info map_info);

int	main(void)
{
	char		**map;
	t_map_info	map_info;
	int			i;
	int			j;

	map_info = ft_height("test.txt");
	map = NULL;
	ft_tab_width(&map_info, "test.txt");
	if (!ft_check_width(map_info))
		printf("Error\n");
	else
		printf("C'est good\n");
	map = ft_map(map_info, "test.txt", map);
	i = 1;
	j = 0;
	ft_print_map(map, map_info);
	ft_fill_square(map, ft_solver(map, map_info), map_info);
	ft_print_map(map, map_info);
	return (0);
}
