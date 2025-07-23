/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:25:01 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/23 15:32:46 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	signe;
	int	resultat;
	int	lenbase;

	if (ft_verif_base(base) == 1)
	{
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
	}
	return (0);
}

// int	main(void)
// {
// 	char	str [18] = "   --+-++-1585a331";
// 	printf("%d", ft_atoi_base(str, "0123456789"));
// 	return (0);
// }