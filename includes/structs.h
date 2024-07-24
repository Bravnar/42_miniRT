/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:33:18 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/24 13:08:37 by smuravye         ###   ########.fr       */
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

typedef struct	s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_tup
{
	double	x;
	double	y;
	double	z;
	bool	is_p;
}	t_tup;

typedef struct	s_rwin
{
	int		x;
	int		y;
}	t_rwin;

typedef struct	s_amb
{
	double	ratio;
	int		rgb[3];
}	t_amb;

typedef struct	s_cam
{
	t_tup	point;
	t_tup	vector;
	int		fov;
}	t_cam;

typedef struct	s_light
{
	t_tup	point;
	double	bright;
	int		rgb[3];			// Bonus
}	t_light;

typedef struct	s_file
{
	int		fd;
	bool	is_valid;
}	t_file;

typedef struct	s_map
{
	t_file		file;
	t_rwin		win;
	t_amb		amb;
	t_cam		cam;
	t_light		light;
	t_obj		*obj_list;
	
}	t_map;

typedef struct	s_main
{
	t_mlx	mlx;
	t_rect	rect;
	t_map	data;
	//view?
	//mouse?
	//kb?
}	t_main;


#endif
