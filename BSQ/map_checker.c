/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:28:53 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 16:50:51 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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

	i = 1;
	while (i < map_info.height)
	{
		if (map_info.width[i] != map_info.width[1])
			return (0);
		i++;
	}
	return (1);
}

char	*isolate_first_line(int fd)
{
	char	buffer[2];
	char	*first_line;
	char	*tmp;
	int		size_read;

	tmp = NULL;
	first_line = malloc(sizeof(char) * 2);
	if (!first_line)
		return (NULL);
	size_read = read(fd, first_line, 1);
	first_line[size_read] = '\0';
	while (size_read == 1 && first_line[ft_strlen(first_line) - 1] != '\n')
	{
		size_read = read(fd, buffer, 1);
		buffer[size_read] = '\0';
		tmp = malloc(sizeof(char) * (ft_strlen(first_line) + 2));
		tmp[0] = '\0';
		ft_strcat(tmp, first_line);
		ft_strcat(tmp, buffer);
		free(first_line);
		first_line = tmp;
	}
	return (first_line);
}

int	first_line_check(char *file_name, char **first_line)
{
	int		fd;
	char	empty;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	*first_line = isolate_first_line(fd);
	empty = (*first_line)[ft_strlen(*first_line) - 3];
	if (empty >= '0' && empty <= '9' || ft_strict_atoi(first_line) <= 0)
		return (-1);
	else
		return (fd);
}

char	**ft_file(int file_open, unsigned long mapsize)
{
	int		bytestock;
	char	*buff;
	char	**result;
	char	*len;

	len = isolate_first_line(file_open);
	mapsize = mapsize * ft_strlen(len) + 1;
	buff = (char *) malloc (sizeof(char) * mapsize);
	ft_strcpy(buff, len);
	bytestock = read(file_open, buff + ft_strlen(len), mapsize - ft_strlen(len));
	buff[bytestock] = '\0';
	close(file_open);
	result = ft_split(buff, "\n");
	free(buff);
	return (result);
}

int	ft_mapcontent(char **map, char obstacle, char void_indic)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != obstacle && map[i][j] != void_indic)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	ft_map_equal(char **map, char obstacle, char void_indic)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (map[0][j])
		j++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != j)
			return (0);
		i ++;
	}
	if (!(ft_mapcontent(map, obstacle, void_indic)))
		return (0);
	return (1);
}
