/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:46:33 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/15 17:59:22 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] && str[i + j] == to_find[j])
			{
				j++;
			}
			if (to_find[j] == 0)
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
