/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:03:28 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/13 18:32:06 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_burningship(t_data *data)
{
	data->fractal_func = burningship;
	data->center_xy.x = BURNINGSHIP_CENTER_X;
	data->center_xy.y = BURNINGSHIP_CENTER_Y;
	if (WIDTH >= HEIGHT)
		data->pixel = WIDTH / 4;
	else
		data->pixel = HEIGHT / 4;
	data->complex_xy.x = WIDTH / data->pixel;
	data->complex_xy.y = HEIGHT / data->pixel;
	init_color(data);
}

int	burningship(t_data *data, int w, int h, int iteration)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp_z_x;

	c_re = data->center_xy.x + (w / data->pixel) - (data->complex_xy.x / 2);
	c_im = data->center_xy.y + (h / data->pixel) - (data->complex_xy.y / 2);
	z_x = c_re;
	z_y = c_im;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) < 4) && (iteration < ITERATION_MAX))
	{
		temp_z_x = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * fabs(z_x * z_y) + c_im;
		z_x = temp_z_x;
		iteration++;
	}
	return (iteration);
}
