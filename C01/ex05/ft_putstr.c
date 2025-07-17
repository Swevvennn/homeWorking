/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:50:11 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/17 18:21:24 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr("abcdefghijklmnopqrstuvxyz");
// 	ft_putstr("1135461435146");
// 	ft_putstr("WAW");
// 	ft_putstr("coooooooooooool");
// 	return (0);
// }
