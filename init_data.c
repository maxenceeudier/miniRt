/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:12:15 by meudier           #+#    #+#             */
/*   Updated: 2022/08/29 20:20:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int     free_data(t_data *data)
{
    t_Objects *temp;

    if (data->lumA)
        free(data->lumA);
    if (data->lum)
        free(data->lum);
    if (data->cam)
        free(data->cam);
    if (data->objects)
    {
        while(data->objects)
        {
            temp = (data->objects);
            if (data->objects->object)
                free(data->objects->object);
            data->objects = data->objects->next;
            free(temp);
        }
    }
    return (0);
}

int     free_tab(char **tab)
{
    int i;

    i = 0;
    while (*(tab + i))
        free(tab[i++]);
    free(tab);
    return (0);
}

int     check_range_vector(t_vector *vector, int min, int max)
{
    if ((vector->x < min || vector->x > max)
        || ((vector->y < min || vector->y > max))
        || (vector->z < min || vector->z > max))
        return (0);
    return (1);
}

int     check_ACL(t_data *data)
{
    t_Objects   *temp;

    if (!data->lumA || !data->lum || !data->cam)
        return (0);
    if ((data->lumA->ratio < 0 || data->lumA->ratio > 1)
        || !check_range_vector(&data->lumA->color, 0, 255))
        return (0);
    if ((data->lum->ratio < 0 || data->lum->ratio > 1)
        || !check_range_vector(&data->lum->color, 0, 255))
        return (0);
    if ((data->cam->fov < 0 || data->cam->fov > 180)
        || !check_range_vector(&data->cam->dir, -1, 1))
        return (0);
    if (data->objects)
    {
        temp = data->objects;
        while (temp)
        {
            if (temp->id == SP)
                if (!check_range_vector(&((t_Sphere *)temp->object)->color, 0, 255))
                    return (0);
            /*else if (id == PL)
                if (!check_range_vector(((t_Plan)temp->object).color, 0, 255))
                    return (0);
            else if (id == CL)
                if (!check_range_vector(((t_Cyldr)temp->object).color, 0, 255))
                    return (0);*/
            temp = temp->next;
        }   
    }
    return (1);
}

int     is_digit(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        i++;
    if (str[i])
        return(0);
    return (1);
}

int     is_float(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        i++;
    if (str[i] == '.')
    {
        i++;
        if (!str[i])
            return (0);
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        i++;
    if (str[i])
        return(0);
    return (1);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
    if (*nptr == '-')
    {
        sign = -1;
    }
	while (*nptr && !(*nptr >= '0' && *nptr <= '9'))
		nptr++;
	while (*nptr && *nptr <= '9' && *nptr >= '0')
	{
		res = res * 10 + ((*nptr) - 48);
		nptr++;
	}
	return (res * sign);
}

float   ft_atof(char *str)
{
    float res;
    float res2;
    int sign;

    sign = 1;
    if (str && *str == '-')
    {
        sign = -1;
        str++;
    }
    res = (float) ft_atoi(str);
    while (*str && *str != '.')
        str++;
    if (*str == '.')
        str++;
    res2 = (float) ft_atoi(str);
    while (res2 > 1)
        res2 /= 10;
    return ((res + res2) * sign);
}

int a_to_vec(char *str, t_vector *vector, int (*f)(char *))
{
    char    **temp;
    int    i;

    temp = ft_split (str, ',');
    if (!temp)
        return (0);
    i = 0;
    while (temp && temp[i])
    {
        
        if (!(*f)(temp[i]) || i >= 3)
            return (free_tab(temp));
        i++;
    }
    vector->x = ft_atof(temp[0]);
    vector->y = ft_atof(temp[1]);
    vector->z = ft_atof(temp[2]);
    free_tab(temp);
    return (1);
}


int     ft_parse_A(t_data *data, char ** line_split)
{
    int     j;

    j = 0;
    while (line_split[j])
        j++;
    if (j != 3 || data->lumA || !is_float(line_split[1]))
        return (0);
    data->lumA = malloc(sizeof(t_LumA));
    if (!data->lumA)
        return (0);
    if (!is_float(line_split[1]))
        return (0);
    data->lumA->ratio = ft_atof(line_split[1]);
    if (!a_to_vec(line_split[2], &data->lumA->color, &is_digit))
        return (0);
    return (1);
}

int ft_parse_C(t_data *data, char ** line_split)
{
    int     j;

    j = 0;
    while (line_split[j])
        j++;
    if (j != 4 || data->cam)
        return (0);
    data->cam = malloc(sizeof(t_Cam));
    if (!data->cam)
        return (0);
    if (!a_to_vec(line_split[1], &data->cam->pos, &is_float))
        return (0);
    if (!a_to_vec(line_split[2], &data->cam->dir, &is_float))
        return (0);
    if (!is_digit(line_split[3]))
        return (0);
    data->cam->fov = ft_atoi(line_split[3]);
    return (1);
}

int ft_parse_L(t_data *data, char **line_split)
{
    int     j;

    j = 0;
    while (line_split[j])
        j++;
    if (j != 4 || data->lum)
        return (0);
    data->lum = malloc(sizeof(t_Lum));
    if (!data->lum)
        return (0);
    if (!a_to_vec(line_split[1], &data->lum->pos, &is_float))
        return (0);
    if (!a_to_vec(line_split[3], &data->lum->color, &is_digit))
        return (0);
    if (!is_float(line_split[2]))
        return (0);
    data->lum->ratio = ft_atof(line_split[2]);
    return (1);
}

int __add_node(t_Objects **data, void *current, int id)
{
    t_Objects   *nouveau;
    t_Objects   *last;

    nouveau = malloc(sizeof(t_Objects));
    if (!nouveau)
        return (0);
    nouveau->id = id;
    nouveau->object = current;
    nouveau->next = NULL;
    nouveau->prev = NULL;
    if (!(*data))
        *data = nouveau;
    else
    {
        last = *data;
        while (last->next)
            last = last->next;
        last->next = nouveau;
        nouveau->prev = last;
    }
    return (1);
}

int ft_parse_sp(t_data *data, char **line_split)
{
    t_Sphere *temp;
    int     j;
    int     res;

    temp = malloc(sizeof(t_Sphere));
    res = 1;
    if (!temp)
        res = 0;
    j = 0;
    while (line_split[j])
        j++;
    if (j != 4)
        res = 0;
    if (!a_to_vec(line_split[1], &temp->center, &is_float))
        res = 0;
    if (!a_to_vec(line_split[3], &temp->color, &is_digit))
        res = 0;
    if (!is_float(line_split[2]))
        res = 0;
    temp->radius = (ft_atof(line_split[2])) / 2;
    if (!res || !__add_node(&data->objects, (void *)temp, SP))
    {
        free(temp);
        return (0);
    }
    return (1);
}

int ft_parse_cl(t_data *data, char **line_split);
int ft_parse_pl(t_data *data, char **line_split);

void    init_ft_parse(int   (*parse_line['s' + 1])(t_data *, char**))
{
    parse_line['A'] = &ft_parse_A;
    parse_line['C'] = &ft_parse_C;
    parse_line['L'] = &ft_parse_L;
    parse_line['s'] = &ft_parse_sp;
    //parse_line['c'] = ft_parse_cl;
    //parse_line['p'] = ft_parse_pl;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (1 && s1 && s2)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int check_id(char *str)
{
    if (ft_strcmp(str, "A") == 0 || ft_strcmp(str, "C") == 0
        || ft_strcmp(str, "L") == 0 || ft_strcmp(str, "sp") == 0
        || ft_strcmp(str, "cy") == 0 || ft_strcmp(str, "pl") == 0)
        return (1);
    return (0);
}

int parse(char *line, t_data *data)
{
    char **line_split;    
    int    (*parse_line['s' + 1])(t_data *, char **);

    init_ft_parse(parse_line);
    line_split = ft_split(line, ' ');
    if (check_id(*line_split))
    {
        if (!(*parse_line[(int)*line])(data, line_split))
        {
            free_tab(line_split);
            return (0);
        }
    }
    free_tab(line_split);
    return (1);
}


void    initialize_data(t_data *data)
{
    data->lumA = NULL;
    data->lum = NULL;
    data->cam = NULL;
    data->objects = NULL;
}


int init_data(int ac, char **av, t_data *data)
{
    int     fd;
    int     ret;
    char    *line;

    line = "start";
    ret = 1;
    if (ac == 2 && is_good_extension(av[1]))
    {
        initialize_data(data);
        fd = open(av[1], O_RDONLY);
        if (fd < 0)
            return (0);
        while (line && ret)
        {
            line = get_next_line(fd);
            if (line)
            {
                if (line[0] != '\n' && line[0])
                    ret = parse(line , data);
                printf("line: %s\n", line);
                free(line);
            }
        }
        if (!ret || !check_ACL(data))
            free_data(data);
        close(fd);
        return (ret);
    }
    return (0);
}