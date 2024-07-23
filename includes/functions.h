/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:36:04 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/23 12:36:04 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* MLX UTILS */

void	draw_rectangle(t_main *rt); //TMP
void	my_pixel(t_mlx *mlx, int x, int y, int color); //IMPORTANT
void	redraw(t_main *rt); //IMPORTANT TO ADAPT


/* INIT */
t_main	*init_main(void);
void	init_mlx(t_mlx  *mlx);
void    init_rect(t_rect *rect);

/* EVENT HANDLER */
int		close_win(void *param);
int		keyboard(int keycode, t_main *rt);
void	handle_events(t_main *rt);

/* TUPLE UTILS */

t_tup	tuple_create(double x, double y, double z, double w);


#endif
