/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:20:23 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 09:49:00 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_wordlen(char *str, char *sep)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != sep[0])
	{
		j = 1;
		while (str[i + j] == sep[j] && str[i + j] && sep[j])
			j++;
		if (!sep[j])
			return (i);
		i++;
	}
	return (i);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	j;
	int	words;
	int	space;

	i = 0;
	if (str[i] == '\0')
		return (0);
	words = 0;
	space = 1;
	while (str[i])
	{
		if (str[i] != sep[0] && space-- == 1)
			words++;
		else if (str[i] == sep[0])
		{
			j = 1;
			while (str[i + j] == sep[j] && str[i + j] && sep[j])
				j++;
			if (!sep[j])
				space = 1;
		}
		i++;
	}
	return (words);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**split;

	i = 0;
	j = 0;
	k = 0;
	split = malloc(sizeof(char *) * count_words(str, sep) + 1);
	while (str[i])
	{
		size = ft_wordlen(str[i], sep);
		split[j] = malloc(sizeof(char) * size + 1);
		while (split[j][k])
			split[j][k++] = str[i++];
		split[j][k] = 0;
		j++;
	}
	split[j] = 0;
	return (split);
}
