/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:48:05 by caaubert          #+#    #+#             */
/*   Updated: 2025/07/29 14:02:26 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

// void    ft_first_line(char *filename)

t_map_info	ft_height(char *filename)
{
	int			fd;
	char		buffer[BUF_SIZE];
	ssize_t		byte_read;
	t_map_info	map_info;

	map_info.height = 1;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		byte_read = read(fd, buffer, BUF_SIZE);
		while (byte_read > 0)
		{
			if (buffer[0] == '\n')
				map_info.height++;
			byte_read = read(fd, buffer, BUF_SIZE);
		}
		return (map_info);
		close(fd);
	}
	close(fd);
	return (map_info);
}

void	ft_tab_width(t_map_info *map_info, char *filename)
{
	int			fd;
	char		buffer[BUF_SIZE];
	ssize_t		byte_read;
	int			i;
	int			j;

	fd = open(filename, O_RDONLY);
	map_info->width = malloc (sizeof(int) * map_info->height);
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		byte_read = read(fd, buffer, BUF_SIZE);
		while (buffer[0] != '\n' && byte_read > 0)
		{
			byte_read = read(fd, buffer, BUF_SIZE);
			j++;
		}
		map_info->width[i] = j;
		i++;
	}
	close(fd);
}

int	ft_check_width(t_map_info map_info)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < map_info.height)
	{
		j = 1;
		while (j < map_info.height)
		{
			if (map_info.width[i] != map_info.width[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_map(t_map_info map_info, char *filename, char **map)
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

// void    ft_first_line(char *map)
