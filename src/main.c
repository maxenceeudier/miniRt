/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:21:17 by meudier           #+#    #+#             */
/*   Updated: 2022/08/30 18:05:26 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	data;

	if (!init_data(ac, av, &data))
		return (printf("--> ERROR INPUT\n"));
	vars.mlx = mlx_init();
	vars.width = 1240;
	vars.heigth = 680;
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.heigth, "miniRt !!");
	if (!vars.win)
		return (1);
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_loop_hook(vars.mlx, &handle_event, &vars);
	mlx_hook(vars.win, 17, 1L >> 17, loop_end, &vars);
	mlx_loop(vars.mlx);
	destroy(&vars);
	free_data(&data);
	return (0);
}
