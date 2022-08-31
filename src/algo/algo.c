/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:53:31 by slahlou           #+#    #+#             */
/*   Updated: 2022/08/31 18:12:00 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

int	get_color(t_Objects	*good)
{
	t_vector	color;
	int	res;

	res = 0;
	if (good && good->id == SP)
		eq_vector(&color, ((t_Sphere *)good->object)->color);
	// else if (good_one->id == PL)
	// 	eq_vector(&color, ((t_plan *)good_one->object).color);
	// else if (good_one->id == CL)
	// 	eq_vector(&color, ((t_cylindre *)good_one->object).color);
	res |= ((int) color.x) << 16;
	res |= ((int) color.y) << 8;
	res |= ((int) color.z);
	return (res);
}

void	algo(t_vars *vars)
{
	t_matrix	matrix;
	t_vector	phit;
	t_vector	phit_temp;
	//t_vector	nhit;
	//t_vector	lum_dir;
	t_vector	pixel;
	t_vector	ray_dir;
	t_Objects	*temp;
	t_Objects	*good_one;
	int 		i;
	int			j;
	float		t_min;
	float		t;

	i = 0;
	good_one = NULL;
	eq_matrix(&matrix, get_transfo_matrix(vars->data.cam->pos, vars->data.cam->dir));
	while (i < HEIGHT - 1)
	{
		j = 0;
		while (j < WIDTH - 1)
		{
			pixel.x = j - WIDTH / 2;
			pixel.y = i - HEIGHT / 2;
			pixel.z = -1 * (WIDTH) / (2 * tanf(((float)vars->data.cam->fov * PI) / (2 * 180) ));
			eq_vector(&ray_dir, vector_x_matrix(normalize(pixel), matrix, 0));
			temp = vars->data.objects;
			t_min = FLT_MAX;
			while (temp)
			{
				t = inter_sphere(ray_dir, vars->data.cam->pos, *(t_Sphere *)temp->object, &phit_temp);
				if (t && t < t_min)
				{
					eq_vector(&phit, phit_temp);
					t_min = t;
					good_one = temp;
				}
				temp = temp->next;
			}
			if (t_min == FLT_MAX)
			{
				img_pix_put(&vars->image, j, i, BACK_GROUND);
			}
			else
			{
				img_pix_put(&vars->image, j, i, get_color(good_one));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.mlx_img, 0, 0);
}
