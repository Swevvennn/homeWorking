/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:46:33 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 12:21:22 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!(to_find[0]))
		return (&str[0]);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] && str[i + j] == to_find[j])
				j++;
			if (!to_find[j])
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%s \n", ft_strstr("abcdefghijklmnopqrstuvwxyz", "m"));
// 	printf("%s \n", ft_strstr("abcdefghijklmnopqrstuvwxyz", "9"));
// 	printf("%s \n", ft_strstr("abcdefghijklmnopqrstuvwxyz", "\0"));
// 	return (0);
// }
