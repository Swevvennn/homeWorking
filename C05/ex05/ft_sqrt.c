/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:29:40 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/18 10:18:38 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_sqrt(9));
// 	printf("%d\n", ft_sqrt(4));
// 	printf("%d\n", ft_sqrt(2));
// 	return (0);
// }
