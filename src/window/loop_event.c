/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:13:34 by meudier           #+#    #+#             */
/*   Updated: 2022/09/08 13:41:29 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

int	handle_event(t_vars *vars)
{
	if (vars->move)
	{
		vars->move = 0;
		algo(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[0].mlx_img, 200, 0);
		mlx_string_put(vars->mlx, vars->win, 50, 200, WHITE, "COUCOU");
	}
	return (0);
}

int	key_event(int keycode, t_vars *vars)
{
	// if (keycode == 32 && !vars->info)
	// {
	// 	vars->info = 1;
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->image[1].mlx_img, 0, 0);
		//mlx_string_put(vars->mlx, vars->win, 200, 200, WHITE, "COUCOU\nCOUCOU\n");
	// }
	// else if (keycode == 32 && vars->info)
	// {
	// 	vars->info = 0;
	// 	mlx_clear_window(vars->mlx, vars->win);
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[0].mlx_img, 0, 0);
	// }
	if (keycode == XK_Escape)
		return (loop_end(vars));
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
