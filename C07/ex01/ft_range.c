/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:44:58 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 12:08:51 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	j;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc((max - min) * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (j < max - min)
	{
		ptr[j] = min + j;
		j++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	int	n;
// 	int	m;
// 	int	*liste;
// 	int	i;

// 	n = 0;
// 	m = 10;
// 	liste = ft_range(n, m);
// 	i = 0;
// 	while (i < m - n)
// 	{
// 		printf("%d", liste[i]);
// 		i++;
// 	}
// 	return (0);
// }
