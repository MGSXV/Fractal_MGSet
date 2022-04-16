/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:15:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 23:20:46 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_julia(t_fractol *data)
{
	data->new = complex_init((data->coord.x * data->x_scale) - data->center_x,
			(data->coord.y * data->y_scale) - data->center_y);
	data->iterations = 0;
	while (data->iterations < data->max_iterations)
	{
		data->old = data->new;
		data->new = complex_init(data->old.r_part * data->old.r_part
				- data->old.i_part * data->old.i_part + data->julia.r_part, 2
				* data->old.r_part * data->old.i_part + data->julia.i_part);
		data->iterations++;
		if ((data->new.r_part * data->new.r_part)
			+ (data->new.i_part * data->new.i_part) > 4)
			break ;
	}
}
