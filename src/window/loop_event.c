/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:13:34 by meudier           #+#    #+#             */
/*   Updated: 2022/09/08 18:20:17 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"
//int		mlx_string_put(t_xvar *xvar,t_win_list *win,
			       //int x,int y,int color,char *string)
void	new_line(int *y, int facteur)
{
	*y += facteur;
}

void	tab(int *x, int tab)
{
	*x += tab;
}

char	*get_str_vector(t_vector v)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;
	char	*temp;
	char	*str;

	temp1 = ftoa(v.x);
	temp2 = ftoa(v.y);
	temp3 = ftoa(v.z);
	temp = ft_strjoin(temp1, ", ");
	free(temp1);
	temp1 = temp;
	temp = ft_strjoin(temp1, temp2);
	free(temp2);
	free(temp1);
	temp1 = temp;
	temp = ft_strjoin(temp1, ", ");
	free(temp1);
	temp1 = temp;
	str = ft_strjoin(temp1, temp3);
	free(temp1);
	free(temp3);
	return (str);
}

void	print_cam(t_vars *vars, t_Cam *cam, int x, int *y)
{
	(void)cam;
	char	*head;
	char	*str;

	head = "C :";
	str = get_str_vector(cam->pos);
	mlx_string_put(vars->mlx, vars->win, x, *y, WHITE, head);
	new_line(y, 20);
	mlx_string_put(vars->mlx, vars->win, x + ft_strlen(head) * 6, *y, WHITE, "pos : ");
	mlx_string_put(vars->mlx, vars->win, x + ft_strlen(head) * 6 + ft_strlen("pos : ") * 6, *y, WHITE, str);
	new_line(y, 20);
	free(str);
	mlx_string_put(vars->mlx, vars->win, x + ft_strlen(head) * 6, *y, WHITE, "dir : ");
	str = get_str_vector(cam->dir);
	mlx_string_put(vars->mlx, vars->win, x + ft_strlen(head) * 6 + ft_strlen("dir : ") * 6, *y, WHITE, str);
	new_line(y, 20);
	free(str);
}

void	print_lum(t_vars *vars, t_Lum *lum, int x, int *y)
{
	(void)lum;
	mlx_string_put(vars->mlx, vars->win, x, *y, WHITE, "L :");
	new_line(y, 20);
}

void	print_menu(t_vars *vars)
{
	int	x;
	int	y;

	x = 10;
	y = 20;
	print_cam(vars, vars->data.cam, x, &y);
	print_lum(vars, vars->data.lum, x, &y);
}

int	handle_event(t_vars *vars)
{
	if (vars->move)
	{
		vars->move = 0;
		algo(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.mlx_img, 0, 0);
	}
	return (0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == 65293 && vars->av)
	{

		free_data(&vars->data);
		if (!init_data(2, vars->av, &vars->data))
			printf("--> ERROR INPUT\n");
		else
			vars->move = 1;

	}
	if (keycode == XK_Escape)
		return (loop_end(vars));
	return (0);
}

int	loop_end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
