/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:34:35 by mosmond           #+#    #+#             */
/*   Updated: 2025/07/17 13:54:10 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc __attribute__((unused)), char **argv)
{
	int	i;

	i = 0;
	while (argv[0][i])
	{
		i++;
	}
	write(1, argv[0], i);
	return (0);
}
