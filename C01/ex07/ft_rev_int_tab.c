/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:10:05 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/17 18:21:28 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i <= size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i ++;
	}
}

// int	main(void)
// {
// 	int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	ft_rev_int_tab(tab, 10);
// 	for(int j = 0; j < 10; j++)
// 	{
//         printf("%d ", tab[j]);
// 	}
// 	return (0);
// }
