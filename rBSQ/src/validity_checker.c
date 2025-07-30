/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:13:26 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/30 14:29:09 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

// void	mass_print(char **map, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < size)
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

int	ft_validity_checker(char *file_name, char ***map, t_map_info **params)
{
	char	*first_line;
	int		fd;

	fd = ft_first_line_check(file_name, &first_line);
	if (fd == -1)
	{
		write(2, "map error fd = -1\n", 18);
		free(first_line);
		return (0);
	}
	*params = ft_param_filler(first_line);
	*map = ft_file(fd, ft_strict_atoi(first_line));
	//mass_print(*map, ft_strict_atoi(first_line));
	if (!ft_map_equal(*map, (*params)->obst, (*params)->empty))
	{
		write(2, "map error from map\n", 19);
		free(first_line);
		ft_big_big_free(*map);
		free(params);
		return (0);
	}
	free(first_line);
	return (1);
}

void	ft_big_big_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}
