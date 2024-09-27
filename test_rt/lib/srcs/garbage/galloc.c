/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:21:30 by hmorand           #+#    #+#             */
/*   Updated: 2024/03/27 20:21:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

/* Gracefully adapted from our very own rude-jes */
/* (Github: https://github.com/RPDJF/betterft/)  */

#include "../../includes/my_lib.h"

void	*galloc(size_t size)
{
	return (addgarbage(malloc(size)));
}
