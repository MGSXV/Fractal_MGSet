/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:10:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 23:16:07 by sel-kham         ###   ########.fr       */
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
	else if (!ft_strncmp(flag, "-s", ft_strlen(flag)))
		ft_printf("Something else");
	else
		ft_error_exit("Error: Invalid argument. \
Try \"--help\" for more information.\n", data, true);
}
