/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bravnar <bravnar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:41:43 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/05 14:55:23 by bravnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// Resets the text to default color and style
# define RESET       "\x1B[0m"

// Regular Colors
# define BLACK       "\x1B[0;30m"
# define RED         "\x1B[0;31m"
# define GREEN       "\x1B[0;32m"
# define YELLOW      "\x1B[0;33m"
# define BLUE        "\x1B[0;34m"
# define MAGENTA     "\x1B[0;35m"
# define CYAN        "\x1B[0;36m"
# define WHITE       "\x1B[0;37m"

// Bold (Bright) Colors
# define BOLD_BLACK   "\x1B[1;30m"
# define BOLD_RED     "\x1B[1;31m"
# define BOLD_GREEN   "\x1B[1;32m"
# define BOLD_YELLOW  "\x1B[1;33m"
# define BOLD_BLUE    "\x1B[1;34m"
# define BOLD_MAGENTA "\x1B[1;35m"
# define BOLD_CYAN    "\x1B[1;36m"
# define BOLD_WHITE   "\x1B[1;37m"
# define BOLD_ORANGE  "\x1B[38;5;214m"

// Underline
# define UNDERLINE    "\x1B[4m"

// Background Colors
# define BG_BLACK     "\x1B[40m"
# define BG_RED       "\x1B[41m"
# define BG_GREEN     "\x1B[42m"
# define BG_YELLOW    "\x1B[43m"
# define BG_BLUE      "\x1B[44m"
# define BG_MAGENTA   "\x1B[45m"
# define BG_CYAN      "\x1B[46m"
# define BG_WHITE     "\x1B[47m"

#endif
