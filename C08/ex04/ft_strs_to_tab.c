/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:01:41 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/24 18:03:16 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(i * sizeof(char));
	j = 0;
	while (src[j])
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*liste;
	int					i;

	i = 0;
	liste = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!liste)
		return (0);
	while (i < ac)
	{
		liste[i].size = ft_strlen(av[i]);
		liste[i].str = ft_strdup(av[i]);
		liste[i].copy = ft_strdup(av[i]);
		i++;
	}
	liste[i].size = 0;
	liste[i].str = 0;
	liste[i].copy = 0;
	return (liste);
}

