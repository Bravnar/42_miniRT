#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* MLX UTILS */

void			draw_rectangle(t_main *rt); //TMP
void			my_pixel(t_mlx *mlx, int x, int y, int color); //IMPORTANT
void			redraw(t_main *rt); //IMPORTANT TO ADAPT

/* INIT */

t_main			*init_main(void);
void			init_mlx(t_mlx  *mlx);
void			init_rect(t_rect *rect);
// t_main	*init_all(void);
t_main	*init_all(char *file_name);
t_map	*get_scene(void);
// t_main	*init_main(void);
// void	init_mlx(t_mlx  *mlx);
// void	init_rect(t_rect *rect);

/* read_rt_file.c */
void	populate_scene_struct(char *file_name, t_map *scene);
void	check_identifier(t_parse **head);
void	read_file(char *file_name, t_map *data);
void	print_scene_details(void);

/* Ambient */
void	populate_amb(void);

/* Camera */
void	populate_cam(void);

/* Light */

void	populate_light(void);

/* light_utils.c */
t_light	*new_light_node(t_tup point, double bright, t_color rgb);
void	add_light_node(t_light **head, t_light *new_node);
void	free_light_nodes(t_light *light);
void	print_light_nodes(t_light **head);

/* Resolution */
void	populate_rwin(void);

/* ft_errorquit.c */
void	err_quit(char *msg);
void	err_handler(t_err code);

/* utils.c */
t_parse	*new_parse_node(char *line);
void	add_node(t_parse **parsed, t_parse *new_node);
void	free_nodes(t_parse *list);
void	print_nodes(t_parse **head);

/* validity.c */

/* counter.c */
void	check_count(void);
void	count_identifier(t_parse **head);

/* ft_stdtod.c */
double	ft_strtod(char *str);
int	ft_strtoi(const char *nptr, char **endptr);

/* EVENT HANDLER */
int				close_win(void *param);
int				keyboard(int keycode, t_main *rt);
void			handle_events(t_main *rt);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:24:20 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/31 17:24:32 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

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

/* VECTOR INFO */

double			vector_mag(t_tup a);
bool			is_unit_vector(t_tup a);
double			vector_dot(t_tup a, t_tup b);

/* PROJECTILES & ENVIRONMENTS */

t_proj			proj_new(t_tup position, t_tup velocity);
t_env			env_new(t_tup wind, t_tup gravity);
t_proj			tick(t_env env, t_proj proj);

/* ************************************************************************** */
/*                                                                            */
/*                                FLOATS                                      */
/*                                                                            */
/* ************************************************************************** */

bool			equal(double a, double b);

/* ************************************************************************** */
/*                                                                            */
/*                                COLORS                                      */
/*                                                                            */
/* ************************************************************************** */

/* COLOR INITIALISATION */

t_color			color(int r, int g, int b);
void			add_hex_color(t_color *c);

/* COLOR OPERATIONS */

t_color			color_add(t_color c1, t_color c2);
t_color			color_sub(t_color c1, t_color c2);
t_color			color_scalarmult(int scalar, t_color c2);
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

bool			is_triangular(t_matrix	A, int	size);
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

t_inter			intersect_sphere(t_ray r, t_obj *sphere);
t_intersection	intersection(double t, t_obj *shape);
t_inter			intersections(int c, ...);

/* HITS */

t_intersection	hit(t_inter inters);

/* RAY TRANSFORMATIONS */

t_ray			ray_transform(t_ray ray, t_matrix transform);

/* ************************************************************************** */
/*                                                                            */
/*                                SHADING                                     */
/*                                                                            */
/* ************************************************************************** */

/* NORMAL */

t_tup			normal_at(t_obj *sphere, t_tup point);

/* REFLECTION */

t_tup			vector_reflect(t_tup in, t_tup normal);

/* LIGHTING */

t_material		material(t_color c, double d, double s, double sh);

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

#endif
