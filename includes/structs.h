/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:34:00 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/24 10:34:00 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct	s_main
{
	//t_parse	parse;
	t_mlx	mlx;
	t_rect	rect;
	//view?
	//mouse?
	//kb?
}	t_main;

typedef struct s_tup
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tup;

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

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				t;
	unsigned int	hex;
}	t_color;

#endif
