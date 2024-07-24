/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:33:24 by smuravye          #+#    #+#             */
/*   Updated: 2024/07/24 15:27:17 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_obj
{
	char			*(*get_name)(struct s_obj shape);
	double			(*volume)(struct s_obj shape);
	void			(*destroy)(struct s_obj shape);
	t_tup			point;
	t_tup			dir_vector; 		//cube/cyllinder/cone/parallelogram
	int				rgb[3];
	struct s_obj	*next;
}	t_obj;

#endif 