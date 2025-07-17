/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:06 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/17 16:58:37 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **str1, char **str2)
{
	char	*to_swap;

	to_swap = *str1;
	*str1 = *str2;
	*str2 = to_swap;
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		n;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap(&argv[j], &argv[j + 1]);
			j++;
		}
		i++;
	}
	n = 1;
	while (n < argc)
	{
		ft_print(argv[n]);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}
