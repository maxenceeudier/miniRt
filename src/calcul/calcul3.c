/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:28:27 by meudier           #+#    #+#             */
/*   Updated: 2022/08/30 18:44:33 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

t_matrix	get_transfo_matrix(t_vector cam_orig, t_vector cam_dir)
{
	t_matrix	matrix;
	t_vector	temp;

	temp.x = 0;
	temp.y = 1;
	temp.z = 0;
	eq_vector(&matrix.forward, float_x_vector(normalize(cam_dir), -1));
	if ((matrix.forward.x == 0 && matrix.forward.y == 1
			&& matrix.forward.z == 0)
		|| ((matrix.forward.x == 0 && matrix.forward.y == -1
				&& matrix.forward.z == 0)))
	{
		matrix.right.x = 1;
		matrix.right.y = 0;
		matrix.right.z = 0;
	}
	else
		eq_vector(&matrix.right, cross_product(temp, matrix.forward));
	eq_vector(&matrix.up, cross_product(matrix.forward, matrix.right));
	eq_vector(&matrix.cam, cam_orig);
	return (matrix);
}

t_vector	vector_x_matrix(t_vector v, t_matrix m, int i)
{
	t_vector	rslt;

	rslt.x = v.x * m.right.x + v.y * m.up.x + v.z * m.forward.x + i * m.cam.x;
	rslt.y = v.x * m.right.y + v.y * m.up.y + v.z * m.forward.y + i * m.cam.y ;
	rslt.z = v.x * m.right.z + v.y * m.up.z + v.z * m.forward.z + i * m.cam.z;
	return (rslt);
}
