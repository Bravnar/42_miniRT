#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* MLX UTILS */

void			draw_rectangle(t_main *rt); //TMP
void			my_pixel(t_mlx *mlx, int x, int y, int color); //IMPORTANT
void			redraw(t_main *rt); //IMPORTANT TO ADAPT

/* INIT */

t_main			*init_main(void);
void			init_mlx(t_mlx *mlx);
void			init_rect(t_rect *rect);
// t_main	*init_all(void);
t_map			*get_scene(void);
t_main			*init_all(char *file_name);
t_obj			*search_obj_list(char *type);
// t_main	*init_main(void);
// void	init_mlx(t_mlx  *mlx);
// void	init_rect(t_rect *rect);

/* scene_getters */
t_rwin			*get_scene_win(void);
t_amb			*get_scene_amb(void);
t_cam			*get_scene_cam(void);
t_light			**get_scene_light(void);
t_obj			**get_scene_objs(void);

/* read_rt_file.c */
void			populate_scene_struct(char *file_name, t_map *scene);
void			check_identifier(t_parse **head);
void			read_file(char *file_name, t_map *data);
void			print_scene_details(void);

/* Ambient */
void			populate_amb(void);

/* Camera */
void			populate_cam(void);

/* Light */

void			populate_light(void);

/* light_utils.c */

t_light			*new_light_node(t_tup point, double bright,
					t_color rgb, t_color i);
void			add_light_node(t_light **head, t_light *new_node);
void			free_light_nodes(t_light *light);
void			print_light_nodes(t_light **head);
void			add_light_node_front(t_light *light, t_light **head);
void			remove_first_light(t_light **head);

/* Resolution */
void			populate_rwin(void);

/* Shapes/Objects */

void			populate_shapes(void);
t_tup			get_vector(char *str);
t_tup			get_point(char *str);
t_color			get_color(char *str);

/* objects_utils.c */
void			print_object_nodes(t_obj **head);

/* ft_errorquit.c */
void			err_quit(char *msg);
void			err_handler(t_err code);

/* utils.c */
t_parse			*new_parse_node(char *line);
void			add_node(t_parse **parsed, t_parse *new_node);
void			free_nodes(t_parse *list);
void			print_nodes(t_parse **head);

/* validity.c */

/* counter.c */
void			check_count(void);
void			count_identifier(t_parse **head);

/* ft_stdtod.c */
double			ft_strtod(char *str);
int				ft_strtoi(const char *nptr, char **endptr);

t_world			create_world(void);
t_inter			intersect_world(t_world w, t_ray r);
t_comps			prepare_comp(t_intersection h, t_ray r);
t_color			shade_hit(t_world w, t_comps comps);
t_color			color_at(t_world w, t_ray r);

t_matrix		view_transform(t_tup from, t_tup to, t_tup up);
t_view_cam		init_camera(double hsize, double vsize, double fov);
void			print_view_cam(t_view_cam cam);
t_ray			ray_for_pixel(t_view_cam cam, double px, double py);
void			render(t_view_cam cam, t_world w, t_main *rt);

/* EVENT HANDLER */
int				close_win(void *param);
int				keyboard(int keycode, t_main *rt);
void			handle_events(t_main *rt);

/* CREATE */

t_tup			tuple(double x, double y, double z, int w);
t_tup			point(double x, double y, double z);
t_tup			vector(double x, double y, double z);

/* TUPLE OPERATIONS */

t_tup			tuple_sub(t_tup a, t_tup b);
t_tup			tuple_add(t_tup a, t_tup b);
t_tup			tuple_neg(t_tup a);

/* VECTOR OPERATIONS */

t_tup			vector_scalar_mult(t_tup a, double scalar);
t_tup			vector_scalar_div(t_tup a, double scalar);
t_tup			vector_norm(t_tup a);
t_tup			vector_cross(t_tup a, t_tup b);
double			dot(t_tup a, t_tup b);
t_tup			normalize(t_tup v);

/* VECTOR INFO */

double			vector_mag(t_tup a);
bool			is_unit_vector(t_tup a);
double			vector_dot(t_tup a, t_tup b);

/* PROJECTILES & ENVIRONMENTS */

t_proj			proj_new(t_tup position, t_tup velocity);
t_env			env_new(t_tup wind, t_tup gravity);
t_proj			tick(t_env env, t_proj proj);

bool			equal(double a, double b);

/* ************************************************************************** */
/*                                                                            */
/*                                COLORS                                      */
/*                                                                            */
/* ************************************************************************** */

/* COLOR INITIALISATION */

t_color			color(double r, double g, double b);
void			add_hex_color(t_color *c);
int				nadd_hex_color(int r, int g, int b, int t);
t_color			black(void);
void			print_color(t_color c);

/* COLOR OPERATIONS */

t_color			color_add(t_color c1, t_color c2);
t_color			color_sub(t_color c1, t_color c2);
t_color			color_scalarmult(double scalar, t_color c2);
t_color			color_product(t_color c1, t_color c2);
t_color			color_blend(t_color c1, t_color c2);

/* ************************************************************************** */
/*                                                                            */
/*                            MATRICES BASICS                                 */
/*                                                                            */
/* ************************************************************************** */

/* MATRICES OPERATIONS */

bool			matrix_compare(t_matrix A, t_matrix B);
t_matrix		matrix_mult(t_matrix A, t_matrix B);
t_column		matrix_mult_col(t_matrix A, t_column b);
t_tup			matrix_mult_tup(t_matrix A, t_tup b);

/* IDENTITY */

t_matrix		identity(void);

/* TRANSPOSE */

t_matrix		transpose(t_matrix A);

/* DETERMINANT */

bool			is_triangular(t_matrix A, int size);
double			diagonal_product(t_matrix A, int size);
double			determinant(t_matrix A, int size);

/* INVERSE */

bool			is_invertible(t_matrix A);
double			cofactor(t_matrix A, int r, int c, int size_M);
t_matrix		inverse(t_matrix A, int size);

/* ************************************************************************** */
/*                                                                            */
/*                            TRANSFORMATIONS                                 */
/*                                                                            */
/* ************************************************************************** */

/* TRANSLATION */

t_matrix		translation_matrix(double x, double y, double z);
t_tup			translate(t_tup point, double x, double y, double z);
t_tup			inverse_translate(t_tup point, double x, double y, double z);

/* SCALING */

t_matrix		scaling_matrix(double x, double y, double z);
t_tup			scale(t_tup point, double x, double y, double z);
t_tup			inverse_scale(t_tup point, double x, double y, double z);

/* ROTATIONS */

t_matrix		rotation_x(double deg);
t_matrix		rotation_y(double deg);
t_matrix		rotation_z(double deg);
t_tup			rotate(t_tup point, double deg, char axis);
t_tup			inverse_rotate(t_tup point, double deg, char axis);

/* SHEARING */

t_shear			shear(double numbers[6]);
t_matrix		shearing_matrix(t_shear sh);
t_tup			shearing(t_tup point, t_shear sh);
t_tup			inverse_shearing(t_tup point, t_shear sh);

/* ************************************************************************** */
/*                                                                            */
/*                              RAYCASTING                                    */
/*                                                                            */
/* ************************************************************************** */

/* RAYS */

t_ray			ray_new(t_tup point, t_tup direction);
t_tup			position(t_ray ray, double t);

/* INTERSECTIONS */

double			discriminant(t_obj *sphere, double *a, double *b);
t_inter			intersect(t_obj *shape);
t_inter			new_inter(int count, t_obj *shape, ...);
t_intersection	intersection(double t, t_obj *shape);
t_inter			intersections(int c, ...);

/* HITS */

t_intersection	hit(t_inter inters);
t_intersection	nhit(t_inter inters);

/* RAY TRANSFORMATIONS */

t_ray			ray_transform(t_ray ray, t_matrix transform);

/* ************************************************************************** */
/*                                                                            */
/*                                SHADING                                     */
/*                                                                            */
/* ************************************************************************** */

/* NORMAL */

t_tup			normal_at(t_obj *shape, t_tup point);

/* REFLECTION */

t_tup			vector_reflect(t_tup in, t_tup normal);

/* LIGHTING */

t_material		material(t_color c, double d, double s, double sh);
t_material		mat_default(void);
t_color			lighting(t_material m, t_tup p, t_tup views[2], bool in_shadow);

/* vs[0] = eye_view, vs[1] = normal_view */

/* LIGHTING UTILS */

t_color			ambient(t_color effective_color, t_material mat);
t_color			diffuse(double ldn, t_material m, t_color eff_color);
t_color			specular(double ldn, t_material m, t_tup v[3]);

/* ************************************************************************** */
/*                                                                            */
/*                                 UTILS                                      */
/*                                                                            */
/* ************************************************************************** */

/* DISPLAY */

void			print_matrix(t_matrix matrix, int size);
void			print_column(t_column column);
void			print_tuple(t_tup tuple);
void			print_ray(t_ray ray);
void			print_cofactors(t_matrix A, int size);
void			print_inter(t_inter i);
void			print_intersection(t_intersection i);

/* MEMORY */

void			free_inter(t_inter inter);

/* SORTING INTERSECTIONS */

t_inter			sort_inter(t_inter inter);

/* ************************************************************************** */
/*                                                                            */
/*                                 TESTS                                      */
/*                                                                            */
/* ************************************************************************** */

/* EQUALS */

bool			equal_color(t_color a, t_color b);
bool			equal_tuple(t_tup a, t_tup b);
bool			equal_matrix(t_matrix a, t_matrix b);
bool			equal_inter(t_inter a, t_inter b);

/* LIGHTING */

void			lighting_test_battery(void);
void			ray_test_battery(void);
void			hit_test_battery(void);

#endif
