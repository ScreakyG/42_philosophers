/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:23:26 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/20 20:36:34 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int is_only_digit(char *str)
{
    int i;

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

int check_argvs(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc < 5 || argc > 6 )
        return (WRONG_INPUT);
    while (argv[i])
    {
        if (!is_only_digit(argv[i]))
            return (WRONG_INPUT);
        i++;
    }
    if (argc == 6 && ft_atoi(argv[5]) <= 0)
        return (WRONG_INPUT);
    if (ft_atoi(argv[1]) < 1) // SI LE NB DE PHILO > 200 PEUT ETRE ERROR
        return (WRONG_INPUT);
    return (1);
}