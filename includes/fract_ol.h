/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/10 22:25:14 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define MANDELBROT		"mandelbrot"
# define JULIA			"julia"
# define BURNINGSHIP	"burningship"
# define SUCCESS		0
# define FAILURE		1

# include <stdio.h>
# include <stdlib.h>

# include "mlx.h"

/* main.c */
int	parse_input(int argc, char *argv[]);

/* utils.c */
int	ft_strcmp(const char *s1, const char *s2);

#endif
