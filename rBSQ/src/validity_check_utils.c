/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:13:19 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/30 13:54:21 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	*ft_isolate_first_line(int fd)
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

int	ft_first_line_check(char *file_name, char **first_line)
{
	int		fd;
	char	empty;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	*first_line = ft_isolate_first_line(fd);
	empty = (*first_line)[ft_strlen(*first_line) - 4];
	if ((empty >= '0' && empty <= '9') || !ft_strict_atoi(*first_line))
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

	len = ft_isolate_first_line(file_open);
	mapsize = mapsize * ft_strlen(len) + 1;
	buff = (char *) malloc (sizeof(char) * mapsize);
	ft_strcpy(buff, len);
	bytestock = read(file_open, buff + ft_strlen(len),
			mapsize - ft_strlen(len));
	buff[bytestock] = '\0';
	close(file_open);
	result = ft_split(buff, "\n");
	free(buff);
	return (result);
}

int	ft_map_check(char **map, char obstacle, char void_indic)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != obstacle && map[i][j] != void_indic)
				return (0);
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
	return (ft_map_check(map, obstacle, void_indic));
}
