/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mlx_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:04:33 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 10:14:05 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	keyboard_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy_data(data);
	else if (KEY_LEFT <= keycode && keycode <= KEY_UP)
		move_center(data, keycode);
	else if (keycode == NUMPAD_4 || keycode == NUMPAD_6)
		change_rgb_ptr(keycode, data);
	else if (keycode == NUMPAD_2 || keycode == NUMPAD_8)
		change_rgb_value(keycode, data);
	draw_fractal(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		data->mouse_xy.x = (x / data->pixel) - (data->complex_xy.x / 2);
		data->mouse_xy.y = -((y / data->pixel) - (data->complex_xy.y / 2));
		if (keycode == SCROLL_UP)
		{
			data->center_xy.x += data->mouse_xy.x * (ZOOM_RATE - 1.0);
			data->center_xy.y -= data->mouse_xy.y * (ZOOM_RATE - 1.0);
			data->pixel *= ZOOM_RATE;
			data->complex_xy.x /= ZOOM_RATE;
			data->complex_xy.y /= ZOOM_RATE;
		}
		else if (keycode == SCROLL_DOWN)
		{
			data->center_xy.x -= data->mouse_xy.x * (ZOOM_RATE - 1.0);
			data->center_xy.y += data->mouse_xy.y * (ZOOM_RATE - 1.0);
			data->pixel /= ZOOM_RATE;
			data->complex_xy.x *= ZOOM_RATE;
			data->complex_xy.y *= ZOOM_RATE;
		}
		draw_fractal(data);
	}
	else if (keycode == MOUSE_LEFT_BUTTON && data->fractal_func == julia)
		data->julia_fixed *= -1;
	return (0);
}

int	mouse_motion_hook(int x, int y, t_data *data)
{
	if (data->fractal_func == julia && data->julia_fixed == -1)
	{
		data->julia_const_xy.x = (x / data->pixel) - (data->complex_xy.x / 2);
		data->julia_const_xy.y = -((y / data->pixel) - (data->complex_xy.y / 2));
		draw_fractal(data);
	}
	return (0);
}

void	move_center(t_data *data, int keycode)
{
	if (keycode == KEY_LEFT)
		data->center_xy.x -= data->complex_xy.x / 10;
	else if (keycode == KEY_RIGHT)
		data->center_xy.x += data->complex_xy.x / 10;
	else if (keycode == KEY_DOWN)
		data->center_xy.y += data->complex_xy.y / 10;
	else if (keycode == KEY_UP)
		data->center_xy.y -= data->complex_xy.y / 10;
}

void	destroy_data(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}
