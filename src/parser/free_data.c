/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:56:35 by meudier           #+#    #+#             */
/*   Updated: 2022/09/09 09:27:14 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft.h"

int	free_data(t_data *data)
{
	t_Objects	*temp;

	if (data->luma)
	{
		free(data->luma);
		data->luma = NULL;
	}
	if (data->lum)
	{
		free(data->lum);
		data->lum = NULL;
	}
	if (data->cam)
	{
		free(data->cam);
		data->cam = NULL;
	}
	if (data->objects)
	{
		while (data->objects)
		{
			temp = (data->objects);
			if (data->objects->object)
				free(data->objects->object);
			data->objects = data->objects->next;
			free(temp);
			temp = NULL;
		}
	}
	return (0);
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}
