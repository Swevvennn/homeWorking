/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:08:00 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/17 18:19:02 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	to_swap;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size - i - 1)
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
	int tab[10] = {1, 3, 0, 5, 6, 9, 7, 4, 2, 8};
	ft_sort_int_tab(tab, 10);
	for(int j = 0; j < 10; j++)
	{
        printf("%d ", tab[j]);
	}
	return (0);
}
