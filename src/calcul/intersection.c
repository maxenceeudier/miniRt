/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:54:32 by slahlou           #+#    #+#             */
/*   Updated: 2022/08/31 16:07:40 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

float	inter_sphere(t_vector dir_pix, t_vector cam_o, t_Sphere sp, t_vector *rslt)
{
	t_vector	oc;
	t_equation	inter;

	eq_vector(&oc, sub_vector(cam_o, sp.center));
	inter.b = scalaire_product(dir_pix, oc) * 2;
	inter.c = (scalaire_product(oc, oc) - (sp.radius * sp.radius));
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

//int	inter_plan(t_vector dir_pix, t_vector cam_o, /*t_plan*/ plan, t_vector *rslt);
//int	inter_cylindre(t_vector dir_pix, t_vector cam_o, /*t_cylindre*/ cylindre, t_vector *rslt);
