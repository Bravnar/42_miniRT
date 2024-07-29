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

typedef struct s_matrix
{
	double	M[4][4];
}	t_matrix;

typedef struct s_column
{
	double	m[4];
}	t_column;

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

#endif
