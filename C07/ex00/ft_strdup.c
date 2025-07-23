/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:13:02 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 12:09:52 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

// int	main(void)
// {
// 	char	*str;

// 	str = "blabla";
// 	printf("%s", str);
// 	printf("%s", ft_strdup(str));
// }
