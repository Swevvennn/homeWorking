/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:13:26 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 17:13:29 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	validity_checker(char *file_name, char ***map, t_map_info **params)
{
	char	*first_line;
	int		fd;

	fd = first_line_check(file_name, &first_line);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		free(first_line);
		return (0);
	}
	*params = param_filler(first_line);
	*map = ft_file(fd, ft_strict_atoi(first_line));
	if (!ft_map_equal(*map, (*params)->obst, (*params)->empty))
	{
		write(2, "map error\n", 10);
		free(first_line);
		big_big_free(*map, (*params)->size);
		free(params);
		return (0);
	}
	free(first_line);
	return (1);
}