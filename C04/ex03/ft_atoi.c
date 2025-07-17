/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:25:59 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/16 14:02:44 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	resultat;

	signe = 1;
	i = 0;
	resultat = 0;
	while (!('0' <= str[i] && str[i] <= '9'))
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}

int	main(void)
{
	char	str [18] = "   -+-++-1585a331";
	printf("%d", ft_atoi(str));
	return (0);
}
