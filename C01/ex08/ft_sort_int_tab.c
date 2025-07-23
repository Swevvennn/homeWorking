/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:08:00 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 12:18:53 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	to_swap;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				to_swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = to_swap;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int tab[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	ft_sort_int_tab(tab, 10);
	for(int j = 0; j < 10; j++)
	{
        printf("%d ", tab[j]);
	}
	return (0);
}
