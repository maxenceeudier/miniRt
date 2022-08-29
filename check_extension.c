/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:33:54 by meudier           #+#    #+#             */
/*   Updated: 2022/08/29 18:41:24 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_good_extension(char *str)
{
	char	*ext;
	int		i;

	i = 0;
	ext = ".rt";
	while (str && str[i] && str[i] != '.')
		i++;
	if (ft_strcmp(str + i, ext) == 0)
		return (1);
	return (0);
}

