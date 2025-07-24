/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:36:51 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/24 18:50:47 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		somme;
	int		i;
	char	*result;

	if (size <= 0)
		return (NULL);
	i = 0;
	somme = ft_strlen(sep) * (size - 1) + 1;
	while (i < size)
		somme += ft_strlen(strs[i++]) + ft_strlen(sep);
	result = malloc(sizeof(char) * somme);
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i++]);
		if (i < size)
			ft_strcat(result, sep);
	}
	return (result);
}

// int	main(void)
// {
// 	char	*liste[] = {"salut"};
// 	char	*sep = ", ";

// 	printf("%s", ft_strjoin(1, liste, sep));
// 	return (0);
// }
