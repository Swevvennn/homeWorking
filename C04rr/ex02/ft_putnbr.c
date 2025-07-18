/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:19:22 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/18 11:49:35 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	int	to_write;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		to_write = n % 10 + 48;
		write(1, &to_write, 1);
	}
}

int	main(void)
{
	int i =0;
	while (i < 1000)
	{
		ft_putnbr(i);
		write(1, "\n", 1);
		i+=7;
	}
	return (0);
}
