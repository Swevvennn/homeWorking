/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:49:16 by caaubert          #+#    #+#             */
/*   Updated: 2025/07/29 09:24:16 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_check_len(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && str[i])
		{
			if (to_find[j + 1] == '\0')
			{
				return (i);
			}
			j++;
		}
		i++;
		if (str[i + 1] == '\0')
			return (i + 1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	if (str[i] == '\0')
		return (0);
	words = 0;
	while (str[i])
	{
		i += ft_check_len(&str[i], charset);
		i += ft_strlen(charset);
		words++;
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**split;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * count_words(str, charset) + 1);
	while (str[i])
	{
		k = 0;
		size = ft_check_len(&str[i], charset);
		split[j] = malloc(sizeof(char) * size + 1);
		while (k < size)
			split[j][k++] = str[i++];
		split[j][k] = '\0';
		j++;
		i += ft_strlen(charset);
	}
	split[j] = NULL;
	return (split);
}
