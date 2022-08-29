/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:30:42 by meudier           #+#    #+#             */
/*   Updated: 2022/08/29 19:46:41 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <mlx_int.h>
# include <X11/keysym.h>

enum type
{
	SP,
	PL,
	CL
};

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_LumA
{
	float	ratio;
	t_vector	color;
}	t_LumA;

typedef struct s_Lum
{
	t_vector	pos;
	t_vector	color;
	float		ratio;
}	t_Lum;

typedef struct s_Cam
{
	t_vector	pos;
	t_vector	dir;
	int			fov;
}	t_Cam;

typedef struct s_Sphere
{
	t_vector	center;
	t_vector	color;
	float		radius;
}	t_Sphere;

typedef struct s_Objects
{
	int					id;
	void				*object;
	struct s_Objects	*next;
	struct s_Objects	*prev;
}	t_Objects;

typedef struct s_data
{
	t_LumA		*lumA;
	t_Lum		*lum;
	t_Cam		*cam;
	t_Objects	*objects;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		heigth;
}	t_vars;

/*in progress */
int		init_data(int ac, char **av, t_data *data);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
int     free_data(t_data *data);

/* mlx handle*/
char	**ft_split(char const *s, char c);
int		free_tab(char **str);
int		destroy(t_vars *vars);
int		handle_event(t_vars *vars);
int		key_event(int keycode, t_vars *vars);
int		loop_end(t_vars *vars);
int		extension_is_good(char *str);
int		is_good_extension(char *str);

#endif
