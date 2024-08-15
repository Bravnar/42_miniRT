#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_tup			t_tup;
typedef struct s_matrix			t_matrix;
typedef struct s_column			t_column;
typedef struct s_color			t_color;
typedef struct s_material		t_material;
typedef struct s_intersection	t_intersection;
typedef struct s_inter			t_inter;
typedef struct s_obj			t_obj;

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
