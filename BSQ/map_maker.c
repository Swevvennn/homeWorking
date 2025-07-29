/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:30:28 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 16:31:20 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	**ft_map_maker(t_map_info map_info, char *filename, char **map)
{
	int			fd;
	char		buffer[BUF_SIZE];
	ssize_t		byte_read;
	int			i;
	int			j;

	fd = open(filename, O_RDONLY);
	map = malloc(sizeof(char *) * map_info.height + 1);
	i = 0;
	while (i < map_info.height)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * map_info.width[1] + 1);
		while (j < map_info.width[i] + 1)
		{
			byte_read = read(fd, buffer, BUF_SIZE);
			map[i][j] = buffer[0];
			j++;
		}
		map[i++][j] = '\0';
	}
	map[i] = NULL;
	close (fd);
	return (map);
}
