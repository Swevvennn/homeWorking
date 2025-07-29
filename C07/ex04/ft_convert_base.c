/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:36:51 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/29 09:20:50 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_putnbr_base(int nbr, char *base, char	*str);
char	*ft_strcat(char *dest, char src);
int		ft_strlen(char *str);
int		ft_recursive_power(int nb, int power);

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' \
			|| base[i] == 32 || (9 <= base[i] && base[i] <= 13))
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

int	ft_pos_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	signe;
	int	resultat;
	int	lenbase;

	lenbase = ft_strlen(base);
	signe = 1;
	i = 0;
	resultat = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (ft_pos_base(str[i], base) > 0)
		resultat = resultat * lenbase + ft_pos_base(str[i++], base);
	return (resultat * signe);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;
	int	lenbase;
	int	lenint;

	if (!(ft_verif_base(base_from) == 1 && ft_verif_base(base_to) == 1))
	{
		nbr = (char *)malloc(sizeof(char) * 1);
		*nbr = 0;
		return (nbr);
	}
	n = ft_atoi_base(nbr, base_from);
	nbr = 0;
	lenbase = ft_strlen(base_to);
	lenint = 1;
	while (ft_recursive_power(lenbase, lenint) < n)
		lenint++;
	nbr = (char *)malloc(sizeof(char) * (lenint + 1));
	nbr = ft_putnbr_base(n, base_to, nbr);
	return (nbr);
}
