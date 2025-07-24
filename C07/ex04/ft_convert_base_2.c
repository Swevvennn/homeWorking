/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:51:04 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/24 18:52:11 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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