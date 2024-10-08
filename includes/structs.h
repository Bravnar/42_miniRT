/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:09:53 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:09:53 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Object libraries */

# include "object.h"
# include "sphere.h"
# include "cube.h"
# include "cylinder.h"
# include "plane.h"

typedef enum e_type
{
	NO_TYPE,
	WINDOW,
	AMBIENT,
	CAMERA,
	LIGHTS,
	OBJECTS,
}	t_type;

typedef enum s_err
{
	NO_ERR,
	ACL_MISSING,
	TOO_MANY_R,
	TOO_MANY_A,
	TOO_MANY_C,
	A_RATIO_RANGE,
	C_VECTOR_RANGE,
	C_FOV_RANGE,
	L_BRIGHT_RANGE,
	UKNOWN_ID,
	R_OVER_PARAM,
	A_OVER_PARAM,
	C_OVER_PARAM,
	L_OVER_PARAM,
	SP_OVER_PARAM,
	PL_OVER_PARAM,
	PL_VECTOR_RANGE,
	CY_VECTOR_RANGE,
	INVALID_NUMBER,
	WRONG_EXT,
	OPEN_FAILED,
	NO_ARGS,
	INVALID_SEP,
}	t_err;

typedef struct s_mlx
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

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_rwin
{
	int		x;
	int		y;
}	t_rwin;

typedef struct s_amb
{
	double		ratio;
	t_color		rgb;
}	t_amb;

typedef struct s_view_cam
{
	double		hsize;
	double		vsize;
	double		fov;
	double		pixel_size;
	double		half_view;
	double		aspect;
	double		half_width;
	double		half_height;
	t_matrix	transf_matrix;
}	t_view_cam;

typedef struct s_cam
{
	t_tup		point;
	t_tup		vector;
	int			fov;
	t_view_cam	view;
}	t_cam;

typedef struct s_light
{
	t_tup			point;
	double			bright;
	t_color			intensity;
	t_color			rgb;
	struct s_light	*next;
}	t_light;

typedef struct s_parse
{
	t_type			type;
	char			*id;
	char			*line;
	char			**line_split;
	int				count;
	struct s_parse	*next;
	bool			is_bonus;
}	t_parse;

typedef struct s_count
{
	int	r;
	int	a;
	int	c;
	int	l;
	int	sp;
	int	cy;
	int	pl;
	int	cu;
}	t_count;

typedef struct s_file
{
	int			fd;
	t_parse		*parse;
	t_count		count;
	bool		is_valid;
}	t_file;

typedef struct s_map
{
	t_file		file;
	t_rwin		win;
	t_amb		amb;
	t_cam		cam;
	t_light		*light;
	t_obj		*obj_list;
}	t_map;

typedef struct s_main
{
	t_mlx	mlx;
	t_rect	rect;
	t_map	*data;
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

typedef struct s_shear
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shear;

typedef struct s_comps
{
	double	t;
	t_obj	*obj;
	t_tup	point;
	t_tup	eyev;
	t_tup	normalv;
	t_tup	reflectv;
	bool	is_inside;
	t_tup	over_point;
	t_tup	under_point;
	double	n1;
	double	n2;
}	t_comps;

typedef struct s_strtoi
{
	const char	*s;
	int			sign;
	int			result;
	int			digit;
	int			digit_count;
}	t_strtoi;

typedef struct s_conv
{
	char	**split;
	double	b_result;
	double	a_result;
	double	final_result;
	int		sign;
}	t_conv;

typedef struct s_world
{
	t_obj	*shapes;
	t_light	*light;
}	t_world;

typedef struct s_cam_ray
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tup	pixel;
}	t_cam_ray;

typedef struct s_mrt
{
	t_mlx	mlx;
	t_map	*map;
	int		is_unlocked;
}	t_mrt;

typedef struct s_errors
{
	char			*err_msg;
	char			*location;
	struct s_errors	*next;
}	t_errors;

#endif
