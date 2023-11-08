/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:23:26 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/08 03:07:35 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_argvs(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		if (!is_only_digit(argv[i]))
			return (0);
		else if (ft_atoi(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (0);
	if (ft_atoi(argv[1]) < 1)
		return (0);
	return (1);
}
