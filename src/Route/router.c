/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:10:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/17 00:05:48 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_router(char *flag, t_fractol *data)
{
	if (!ft_strncmp(flag, "-m", ft_strlen(flag)))
	{
		data->value1 = 0;
		ft_fractol(data, &ft_mandelbrot);
	}
	else if (!ft_strncmp(flag, "-j", ft_strlen(flag)))
	{
		data->julia = complex_init(.285, .01);
		data->value1 = 1;
		ft_fractol(data, &ft_julia);
	}
	else if (!ft_strncmp(flag, "-b", ft_strlen(flag)))
	{
		data->value1 = 2;
		ft_fractol(data, &ft_burning_ship);
	}
	else
		ft_error_exit("Error: Invalid argument. \
Try \"--help\" for more information.\n", data, true);
}
