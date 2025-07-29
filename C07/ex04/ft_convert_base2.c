/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:51:04 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 09:20:57 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char src)
{
	int	i;

	i = ft_strlen(dest);
	dest[i] = src;
	dest[i + 1] = 0;
	return (dest);
}

char	*ft_putnbr_base(int nbr, char *base, char	*str)
{
	int		lenbase;

	if (nbr < 0)
	{
		ft_strcat(str, '-');
		nbr = -nbr;
	}
	lenbase = ft_strlen(base);
	if (nbr >= lenbase)
		ft_putnbr_base(nbr / lenbase, base, str);
	str = ft_strcat(str, base[nbr % lenbase]);
	return (str);
}
