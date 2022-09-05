/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:50:22 by slahlou           #+#    #+#             */
/*   Updated: 2022/09/05 16:22:54 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"


t_vector	get_luminosity(t_vars *vars, t_vector hit_point, t_vector n_hit, float transmission)
{
	t_vector	luminosity;
	t_vector	lum_dir;
	t_vector	p_lum;
	float		ld;

	eq_vector(&p_lum, sub_vector(vars->data.lum->pos, hit_point));
	eq_vector(&lum_dir, normalize(p_lum));
	if (transmission == FLT_MAX || transmission > norme(p_lum))
		transmission = 1;
	else
		transmission = 0.8;
	ld = transmission * vars->data.lum->ratio * (1000000 / scalaire_product(p_lum, p_lum)) * max(0, scalaire_product(n_hit, lum_dir)) + (100 * vars->data.luma->ratio);
	luminosity.x = 255 - ld;
	luminosity.y = 255 - ld;
	luminosity.z = 255 - ld;
	return (luminosity);
}

t_vector	check_obstruction(t_vars *vars, t_vector hit_point, t_vector n_hit, t_Objects *objects)
{
	t_vector	lum_dir;
	float		transmission;
	t_Objects	*current;

	current = objects;
	eq_vector(&lum_dir, normalize(sub_vector(vars->data.lum->pos, hit_point)));
	rewind_list(&objects);
	loop_object_hit(&objects, lum_dir, add_vector(hit_point, float_x_vector(n_hit, 0.01)), &transmission);
	if (current->id == SP)
		return (sub_vector(((t_Sphere *)current->object)->color, get_luminosity(vars, hit_point, n_hit, transmission)));
	else if (current->id == PL)
		return (sub_vector(((t_plan *)current->object)->color, get_luminosity(vars, hit_point, n_hit, transmission)));
	else if (current->id == CL)
		return (sub_vector(((t_cylindre *)current->object)->color, get_luminosity(vars, hit_point, n_hit, transmission)));
	else
		return (((t_Sphere *)current->object)->color);

}

void	algo_shadow(t_vars *vars, t_vector hit_point, int i, int j)
{
	t_vector	n_hit;

	if (vars->data.objects->id == SP)
		eq_vector(&n_hit, normalize(sub_vector(hit_point, \
		((t_Sphere *)vars->data.objects->object)->center)));
	else if (vars->data.objects->id == PL)
		eq_vector(&n_hit, normalize(((t_plan *)vars->data.objects->object)->normal_vec));
	else if (vars->data.objects->id == CL)
	{
		t_vector	dir_cl = normalize(((t_cylindre *)vars->data.objects->object)->dir);
		t_vector	temp ;
		t_vector	temp2;
		temp.x = 0;
		temp.y = 1;
		temp.z = 0;
		eq_vector(&temp2 , (cross_product(normalize(temp), dir_cl)));
		eq_vector(&n_hit, cross_product(dir_cl, temp2));
	}
	img_pix_put(&vars->image, j, i, shift_color(check_obstruction\
	(vars, hit_point, n_hit, vars->data.objects)));
}
