/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:19:22 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/21 08:45:37 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	to_write;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		to_write = nb % 10 + 48;
		write(1, &to_write, 1);
	}
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 1000)
// 	{
// 		ft_putnbr(i);
// 		write(1, "\n", 1);
// 		i += 7;
// 	}
// 	return (0);
// }
