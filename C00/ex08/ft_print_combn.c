/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:10:56 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 10:58:22 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_int_printer(int n, int i, int x)
{
	char	to_write;

	to_write = x + 48;
	if (i >= n || x == 10)
	{
		write(1, &to_write, 1);
		write(1, ", ", 2);
	}
	else
	{
		while (x < 9)
		{
			x++;
			write(1, &to_write, 1);
			ft_int_printer(n, i + 1, x);
		}
	}

}
// tableau de 10 rempli avec les n premiers 
// elements qui sont modifies puis le tableau et affiche

void	ft_print_combn(int n)
{
	int	i;

	if (0 < n && n < 10)
	{
		i = 0;
		while (i <= 10 - n)
		{
			ft_int_printer(n, 1, i);
			i++;
		}
	}
}

// int	main(void)
// {
// 	ft_print_combn(5);
// 	return (0);
// }
