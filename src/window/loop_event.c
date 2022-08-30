/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:13:34 by meudier           #+#    #+#             */
/*   Updated: 2022/08/30 18:06:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

int	handle_event(t_vars *vars)
{
	(void)vars;
	return (0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (loop_end(vars));
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
