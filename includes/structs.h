#ifndef STRUCTS_H
# define STRUCTS_H

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
//	MORE_TO_BE_ADDED,
}	t_err;

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

/* Object libraries */
# include "object.h"
# include "sphere.h"
# include "cube.h"
# include "cylinder.h"
# include "plane.h"

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
	t_color			rgb;			// Bonus
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

typedef struct	s_count
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

typedef struct	s_map
{
	t_file		file;
	t_rwin		win;
	t_amb		amb;
	t_cam		cam;
	t_count		count;
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

typedef struct s_matrix
{
	double	M[4][4];
}	t_matrix;

typedef struct s_column
{
	double	m[4];
}	t_column;

typedef struct s_shear
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shear;

typedef struct s_ray
{
	t_tup	point;
	t_tup	direction;
}	t_ray;

typedef struct s_intersection
{
	t_obj	*shape;
	double	t;
}	t_intersection;

typedef struct s_inter
{
	int				count;
	t_intersection	*i;
}	t_inter;

typedef struct s_strtoi
{
	const char	*s;
	int		sign;
	int		result;
	int		digit;
	int		digit_count;
}	t_strtoi;

typedef	struct s_conv
{
	char	**split;
	double	b_result;
	double	a_result;
	double	final_result;
	int		sign;
}	t_conv;

#endif
