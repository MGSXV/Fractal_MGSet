/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madelbrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:26:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 22:19:02 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_mandelbrot(t_fractol *data)
{
	data->new = complex_init(0.0, 0.0);
	data->cons = complex_init((data->coord.x * data->x_scale) - data->center_x, \
							(data->coord.y * data->y_scale) - data->center_y);
	data->iterations = 0;
	while (data->iterations < data->max_iterations)
	{
		data->old = data->new;
		data->new = complex_init(data->old.r_part * data->old.r_part
				- data->old.i_part * data->old.i_part + data->cons.r_part, \
				2 * data->old.r_part * data->old.i_part + data->cons.i_part);
		data->iterations++;
		if ((data->new.r_part * data->new.r_part)
			+ (data->new.i_part * data->new.i_part) > 4)
			break ;
	}
}
