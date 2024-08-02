#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_obj
{
	char			*(*get_name)(struct s_obj *shape);
	double			(*volume)(struct s_obj *shape);
	void			(*destroy)(struct s_obj *shape);
	void			(*transform)(struct s_obj *shape, t_matrix transform);
	t_tup			point;
	t_tup			dir_vector; 		//cube/cyllinder/cone/parallelogram
	t_material		material;
	t_matrix		transformation;
	t_matrix		inverse_transformation;
	struct s_obj	*next;
}	t_obj;

#endif
