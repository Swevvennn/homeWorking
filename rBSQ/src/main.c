/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:07:43 by caaubert          #+#    #+#             */
/*   Updated: 2025/07/29 17:40:09 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_follow_main(char **map, t_map_info map_info);

int	main(int argc, char **argv)
{
	int		i;
	char	buffer;
	int		nbytes;

	if (argc == 1)
	{
		nbytes = read(1, buffer, 1);
	}
	else
	{
		i = 1;
		fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{
			
		}
	}
}
