/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:34:00 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/26 15:23:25 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		win_x;
	int		win_y;
}	t_mlx;

typedef struct s_tup
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tup;

# include "object.h"

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				t;
	unsigned int	hex;
}	t_color;

typedef struct	s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct	s_rwin
{
	int		x;
	int		y;
}	t_rwin;

typedef struct	s_amb
{
	double		ratio;
	t_color		rgb;
}	t_amb;

typedef struct	s_cam
{
	t_tup	point;
	t_tup	vector;
	int		fov;
}	t_cam;

typedef struct	s_light
{
	t_tup			point;
	double			bright;
	int				rgb[3];			// Bonus
	struct s_light	*next;
}	t_light;

typedef struct s_parse
{
	char 			*line;
	char 			**line_split;
	struct s_parse	*next;
}	t_parse;

typedef struct	s_file
{
	int		fd;
	t_parse	*parse;
	bool	is_valid;
}	t_file;

typedef struct	s_map
{
	t_file		file;
	t_rwin		win;
	t_amb		amb;
	t_cam		cam;
	t_light		*light;
	t_obj		*obj_list;
	
}	t_map;

typedef struct	s_main
{
	t_mlx	mlx;
	t_rect	rect;
	t_map	*data;
	//view?
	//mouse?
	//kb?
}	t_main;

typedef struct s_projectile
{
	t_tup	position;
	t_tup	velocity;
}	t_proj;

typedef struct s_environment
{
	t_tup	gravity;
	t_tup	wind;
}	t_env;


#endif
