/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:34:15 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/10 13:56:00 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(int a, int b)
{
	char	text;

	if (a + b > 1)
	{
		write(1, ", ", 1);
	}
	text = (a / 10) + '0';
	write(1, &text, 1);
	text = (a % 10) + '0';
	write(1, &text, 1);
	write(1, " ", 1);
	text = (b / 10) + '0';
	write(1, &text, 1);
	text = (b % 10) + '0';
	write(1, &text, 1);
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_print_numbers(a, b);
			b++;
		}
		a++;
	}
}
