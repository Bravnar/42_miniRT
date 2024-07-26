/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:06:39 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/26 14:06:39 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				t;
	unsigned int	hex;
}	t_color;

typedef struct s_obj
{
	char			*(*get_name)(struct s_obj *shape);
	double			(*volume)(struct s_obj *shape);
	void			(*destroy)(struct s_obj *shape);
	t_tup			point;
	t_tup			dir_vector; 		//cube/cyllinder/cone/parallelogram
	t_color			color;
	struct s_obj	*next;
}	t_obj;

#endif
