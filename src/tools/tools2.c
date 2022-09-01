/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:54:00 by slahlou           #+#    #+#             */
/*   Updated: 2022/09/01 17:54:14 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
