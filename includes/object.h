#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_tup
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tup;

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

typedef struct s_column
{
	double	m[4];
}	t_column;

typedef struct s_color
{
	double			r;
	double			g;
	double			b;
	unsigned int	hex;
}	t_color;

typedef enum s_patt_type
{
	PLAIN,
	STRIPE,
	CHECKER,
	GRADIENT,
}	t_patt_type;

typedef struct s_obj	t_obj;

typedef struct s_pattern
{
	t_color		colors[2];
	t_patt_type	type;
	t_color		(*color_at)(t_obj *shape, t_tup point, struct s_pattern pat);
	void		(*transform)(struct s_pattern *pat, t_matrix transformation);
	t_matrix	transformation;
	t_matrix	inverse_transformation;
}	t_pattern;

typedef struct s_material
{
	double		amb;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
	double		transparency;
	double		refractive_index;
	t_pattern	pattern;
	t_color		color;
}	t_material;

typedef struct s_obj	t_obj;

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

typedef struct s_ray
{
	t_tup	point;
	t_tup	direction;
}	t_ray;

typedef struct s_obj
{
	char			*(*get_name)(t_obj *shape);
	double			(*volume)(t_obj *shape);
	void			(*destroy)(t_obj *shape);
	void			(*transform)(t_obj *shape, t_matrix transform);
	t_inter			(*local_intersect)(t_ray ray, t_obj *shape);
	t_tup			(*local_normal_at)(t_obj *shape, t_tup point);
	t_tup			point;
	t_tup			dir_vector; 		//cube/cyllinder/cone/parallelogram
	t_material		material;
	t_matrix		transformation;
	t_matrix		inverse_transformation;
	t_ray			saved_ray;
	struct s_obj	*next;
}	t_obj;

#endif
