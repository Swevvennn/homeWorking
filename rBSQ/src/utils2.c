/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:25:01 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 17:25:19 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

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