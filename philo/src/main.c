/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:47 by fgonzale          #+#    #+#             */
/*   Updated: 2023/08/01 14:35:50 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_argvs(argc, argv))
		return (print_help(), 1);
	if (!init(argc, argv, &data))
		return (printf("Init error\n"), 1);
	start_threads(&data);
	wait_threads(&data);
	destroy_mutex(&data);
	free_exit(&data);
}
