/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:19:22 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/17 10:21:33 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr(int n)
{
	int	to_write;

	if (n == INT_MIN)
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
		if (n > 10)
		{
			ft_putnbr(n / 10);
		}
		to_write = n % 10 + 48;
		write(1, &to_write, 1);
	}
}

// int	main(void)
// {
// 	ft_putnbr(474575);
// 	return (0);
// }
