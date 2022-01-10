/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:03:35 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/10 22:27:48 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char *argv[])
{
	if (parse_input(argc, argv) == FAILURE)
	{
		printf("usage : %s [mandelbrot | julia number | burningship]\n", argv[0]);
		exit(EXIT_SUCCESS);
	}

	return (0);
}

int	parse_input(int argc, char *argv[])
{
	char	*str;

	if (argc < 2)
		return (FAILURE);
	str = argv[1];
	if (ft_strcmp(str, MANDELBROT) == 0)
	{
		return (SUCCESS);
	}
	else if (ft_strcmp(str, JULIA) == 0)
	{
		return (SUCCESS);
	}
	else if (ft_strcmp(str, BURNINGSHIP) == 0)
	{
		return (SUCCESS);
	}
	return (FAILURE);
}
