/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:27:56 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/22 11:40:52 by smuravye         ###   ########.fr       */
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



#endif