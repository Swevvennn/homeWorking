/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:36:49 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 08:50:01 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_decompress(unsigned int nbr, char *base, unsigned int nbase)
{
	if (nbr >= nbase)
		ft_decompress(nbr / nbase, base, nbase);
	write(1, &base[nbr % nbase], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	x;

	if (ft_verif_base(base) == 1)
	{
		{
			if (nbr < 0)
				write(1, "-", 1);
			x = nbr;
			i = 0;
			while (base[i])
				i++;
			ft_decompress(x, base, i);
		}
	}
}

// int	main(void)
// {
// 	ft_putnbr_base(255, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(2147483647, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(123456789, "abcdefghijklmnopqrstuvwxyz");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "poneyvif");
// 	write(1, "\n", 1);
// 	return (0);
// }
