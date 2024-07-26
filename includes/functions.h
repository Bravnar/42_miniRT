/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:15:12 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/26 16:02:27 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* MLX UTILS */

void	draw_rectangle(t_main *rt); //TMP
void	my_pixel(t_mlx *mlx, int x, int y, int color); //IMPORTANT
void	redraw(t_main *rt); //IMPORTANT TO ADAPT


/* INIT */
// t_main	*init_all(void);
t_main	*init_all(char *file_name);
t_map	*get_scene(void);
// t_main	*init_main(void);
// void	init_mlx(t_mlx  *mlx);
// void	init_rect(t_rect *rect);

/* ************************************************************************** */
/*                                                                            */
/*                            PARSING                                         */
/*                                                                            */
/* ************************************************************************** */

/* read_rt_file.c */
void	populate_scene_struct(char *file_name, t_map *scene);
void	populate_rwin(void);
void	populate_amb(void);
void	get_amb_rgb(char *str);
void	check_identifier(t_parse **head);
void	read_file(char *file_name, t_map *data);
void	print_scene_details(void);


/* utils.c */
t_parse	*new_parse_node(char *line);
void	add_node(t_parse **parsed, t_parse *new_node);
void	free_nodes(t_parse *list);
void	print_nodes(t_parse **head);

/* validity.c */

/* ft_stdtod.c */


/* EVENT HANDLER */
int		close_win(void *param);
int		keyboard(int keycode, t_main *rt);
void	handle_events(t_main *rt);

/* ************************************************************************** */
/*                                                                            */
/*                            TUPLES/VECTORS                                  */
/*                                                                            */
/* ************************************************************************** */

/* CREATE */

t_tup	tuple(double x, double y, double z, int w);
t_tup	point(double x, double y, double z);
t_tup	vector(double x, double y, double z);

/* TUPLE OPERATIONS */

t_tup	tuple_sub(t_tup a, t_tup b);
t_tup	tuple_add(t_tup a, t_tup b);
t_tup	tuple_neg(t_tup a);

/* VECTOR OPERATIONS */

t_tup	vector_scalar_mult(t_tup a, double scalar);
t_tup	vector_scalar_div(t_tup a, double scalar);
t_tup	vector_norm(t_tup a);
t_tup	vector_cross(t_tup a, t_tup b);

/* VECTOR INFO */

double	vector_mag(t_tup a);
bool	is_unit_vector(t_tup a);
double	vector_dot(t_tup a, t_tup b);

/* PROJECTILES & ENVIRONMENTS */

t_proj	proj_new(t_tup position, t_tup velocity);
t_env	env_new(t_tup wind, t_tup gravity);
t_proj	tick(t_env env, t_proj proj);

/* ************************************************************************** */
/*                                                                            */
/*                                FLOATS                                      */
/*                                                                            */
/* ************************************************************************** */

bool	equal(double a, double b);

/* ************************************************************************** */
/*                                                                            */
/*                                COLORS                                      */
/*                                                                            */
/* ************************************************************************** */

/* COLOR INITIALISATION */

t_color	color(int r, int g, int b);
void	add_hex_color(t_color *c);

/* COLOR OPERATIONS */

t_color	color_add(t_color c1, t_color c2);
t_color	color_sub(t_color c1, t_color c2);
t_color	color_scalarmult(int scalar, t_color c2);
t_color	color_product(t_color c1, t_color c2);
t_color	color_blend(t_color c1, t_color c2);

#endif
