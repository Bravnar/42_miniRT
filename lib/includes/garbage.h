/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:16:57 by hmorand           #+#    #+#             */
/*   Updated: 2024/05/21 10:50:11 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdlib.h>

typedef struct s_garbage
{
	void				*content;
	struct s_garbage	*next;
	struct s_garbage	*previous;
}	t_garbage;

void		gfree(void *address);
void		*galloc(size_t size);
void		cleargarbage(void);
t_garbage	**getgarbage(void);
t_garbage	*lastgarbage(t_garbage *garb);
void		*addgarbage(void *address);

#endif
