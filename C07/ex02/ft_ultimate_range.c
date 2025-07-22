/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:58:49 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/22 08:17:11 by mosmond          ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		range[0] = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	return (max - min);
}

// int	main(void)
// {
// 	int	*range;
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = ft_ultimate_range(&range, 10, 2);
// 	while (i < size)
// 	{
// 		printf("%d", range[i]);
// 		i++;
// 	}
// 	return (0);
// }
