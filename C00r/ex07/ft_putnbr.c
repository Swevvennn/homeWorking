/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:52:05 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/15 18:18:53 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	ft_decompress(int n)
{
	if (n > 10)
	{
		ft_decompress(n / 10);
	}
	n = n % 10;
	n += 48;
	write(1, &n, 1);
	return (0);
}

int	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ft_decompress(-n);
	}
	else
	{
		ft_decompress(n);
	}
	return (0);
}
