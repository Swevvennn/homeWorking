/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:36:51 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 14:35:49 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
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
	int		i;
	int		somme;
	int		lensep;
	char	*result;

	i = 0;
	somme = 0;
	lensep = ft_strlen(sep);
	while (strs[i])
		i++;
	if (i != size)
		return (0);
	i = 0;
	while (i < size)
		somme += ft_strlen(strs[i++]);
	somme += lensep * (size - 1);
	result = (char *)malloc(somme * sizeof(char));
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i++]);
		if (i != size)
			result = ft_strcat(result, sep);
	}
	return (result);
}

// int	main(void)
// {
// 	char	*liste[] = {"caca", "coucou", "salut"};
// 	char	*sep = ", ";

// 	printf("%s", ft_strjoin(0, liste, sep));
// 	return (0);
// }
