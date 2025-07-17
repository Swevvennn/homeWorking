/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:38:44 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/10 11:00:10 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_text(int a, int b, int c)
{
	char	text;

	if (a + b + c > 3)
	{
		write(1, ", ", 2);
	}
	text = a + '0';
	write(1, &text, 1);
	text = b + '0';
	write(1, &text, 1);
	text = c + '0';
	write(1, &text, 1);
}

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	while (a < 8)
	{
		b = a + 1;
		while (b < 9)
		{
			c = b + 1;
			while (c < 10)
			{
				ft_print_text(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
