/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:48:01 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/13 18:41:11 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_julia(t_data *data)
{
	data->fractal_func = julia;
	data->center_xy.x = JULIA_CENTER_X;
	data->center_xy.y = JULIA_CENTER_Y;
	if (WIDTH >= HEIGHT)
		data->pixel = WIDTH / 8;
	else
		data->pixel = HEIGHT / 8;
	data->complex_xy.x = WIDTH / data->pixel;
	data->complex_xy.y = HEIGHT / data->pixel;
	data->julia_const_xy.x = JULIA_CONST_X;
	data->julia_const_xy.y = JULIA_CONST_Y;
	data->julia_fixed = -1;
	init_color(data);
}

int	julia(t_data *data, int w, int h, int iteration)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp_z_x;

	z_x = data->center_xy.x + ((w / data->pixel) - (data->complex_xy.x / 2));
	z_y = data->center_xy.y + ((h / data->pixel) - (data->complex_xy.y / 2));
	c_re = data->julia_const_xy.x;
	c_im = data->julia_const_xy.y;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) < 4) && (iteration < ITERATION_MAX))
	{
		temp_z_x = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * z_x * z_y + c_im;
		z_x = temp_z_x;
		iteration++;
	}
	return (iteration);
}
