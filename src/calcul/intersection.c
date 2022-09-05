/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:54:32 by slahlou           #+#    #+#             */
/*   Updated: 2022/09/05 18:41:03 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

float	inter_sphere(t_vector dir_pix, t_vector cam_o, void *sphere, t_vector *rslt)
{
	t_vector	oc;
	t_equation	inter;
	t_Sphere	*sp;

	sp = (t_Sphere *)sphere;
	eq_vector(&oc, sub_vector(cam_o, sp->center));
	inter.b = scalaire_product(dir_pix, oc) * 2;
	inter.c = (scalaire_product(oc, oc) - (sp->radius * sp->radius));
	inter.delta = (inter.b * inter.b) - (4 * inter.c);
	if (inter.delta >= 0)
	{
		inter.t1 = ((inter.b * -1) - sqrtf(inter.delta)) / 2;
		inter.t2 = ((inter.b * -1) + sqrtf(inter.delta)) / 2;
		if (inter.t2 < 0)
			return (0);
		if (inter.t1 > 0)
			inter.t = inter.t1;
		else
			inter.t = inter.t2;
		eq_vector(rslt, add_vector(cam_o, float_x_vector(dir_pix, inter.t)));
	}
	else
		return (0);
	return (inter.t);
}

float	inter_plan(t_vector dir_pix, t_vector cam_o, void *plan, t_vector *rslt)
{
	t_plan		*pl;
	float		d;
	float		t;
	t_vector	pl_normal;

	t = 0;
	d = 0;
	pl = (t_plan *)plan;
	eq_vector(&pl_normal, normalize(pl->normal_vec));
	d = ((pl->origin.x * pl_normal.x) + (pl->origin.y * pl_normal.y) + (pl->origin.z * pl_normal.z)) * -1;
	if (scalaire_product(pl_normal, dir_pix))
		t = -1 * ((scalaire_product(pl_normal, cam_o) + d) / (scalaire_product(pl_normal, dir_pix)));
	eq_vector(rslt, add_vector(cam_o, float_x_vector(dir_pix, t)));
	return ((t > 0) * t);
}


// float	inter_cylindre(t_vector dir_pix, t_vector cam_o, void *cylindre, t_vector *rslt)
// {
// 	t_cylindre	*cl;
// 	t_equation	inter;
// 	t_vector	n_cldir;
// 	t_vector	new_cam_o;
// 	t_vector	new_dir_pix;
// 	t_matrix	matrix_cl;

// 	cl = (t_cylindre *) cylindre;
// 	eq_vector(&n_cldir, normalize(cl->dir));
// 	eq_matrix(&matrix_cl, get_transfo_matrix(cl->base, n_cldir));
// 	eq_vector(&new_cam_o, vector_x_matrix(cam_o, matrix_cl, 1));
// 	eq_vector(&new_dir_pix, normalize(vector_x_matrix(dir_pix, matrix_cl, 0)));

// 	inter.a = ((new_dir_pix.x * new_dir_pix.x) + (new_dir_pix.y * new_dir_pix.y));
// 	inter.b = 2 * ((new_cam_o.x * new_dir_pix.x) + (new_cam_o.y * new_dir_pix.y));
// 	inter.c = (-1 * (cl->radius * cl->radius)) + (new_cam_o.x * new_cam_o.x) + (new_cam_o.y * new_cam_o.y);
// 	inter.delta = (inter.b * inter.b) - (4 * inter.a * inter.c);
// 	if (inter.delta >= 0)
// 	{
// 		inter.t1 = ((inter.b * -1) - sqrtf(inter.delta)) / 2;
// 		inter.t2 = ((inter.b * -1) + sqrtf(inter.delta)) / 2;
// 		if (inter.t2 < 0)
// 			return (0);
// 		if (inter.t1 > 0)
// 			inter.t = inter.t1;
// 		else
// 			inter.t = inter.t2;
// 		eq_vector(rslt, vector_x_matrix(add_vector(new_cam_o, float_x_vector(new_dir_pix, inter.t)), matrix_cl, 1));
// 	}
// 	else
// 		return (0);
// 	return (inter.t);
// }


float	inter_cylindre(t_vector dir_pix, t_vector cam_o, void *cylindre, t_vector *rslt)
{
		float a;
        float b;
        float c;
        float delta;
		float t1;
		float t2;
		float t;
		float xp = dir_pix.x * cos(20) + dir_pix.y * sin(20);
		float yp = dir_pix.y * cos(45) + dir_pix.z * sin(45);
		//float zp = ;

		// deg = 70;
		t_cylindre	*cl;
		cl = (t_cylindre *) cylindre;
		eq_vector(&dir_pix, normalize(dir_pix));
        a = xp * xp + yp * yp;
        b = 2 * xp * (cam_o.x - cl->base.x) + 2 * yp * (cam_o.y - cl->base.y);
        c = (cam_o.x - cl->base.x) * (cam_o.x - cl->base.x) + (cam_o.y - cl->base.y) * (cam_o.y - cl->base.y) - cl->radius * cl->radius;
        delta = b * b - 4 * a * c;
		if (delta >= 0)
		{
			t1 = ((b * -1) - sqrtf(delta)) / (2 * a);
			t2 = ((b * -1) + sqrtf(delta)) / (2 * a);
			if (t2 < 0)
				return (0);
			if (t1 > 0)
				t = t1;
			else
				t = t2;
			eq_vector(rslt, add_vector(cam_o, float_x_vector(dir_pix, t)));
		}
		else
			return (0);
		return (t);
			return (-1);
}
