/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madelbrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:26:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/14 04:33:14 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_mandelbrot(t_img_buff *data)
{
	t_coor		coord;
	t_complex	new;
	t_complex	old;
	int			i;

	double zoom = 1, moveX = -0.5, moveY = 0; // Edit later
	coord.y = 0;
	ft_new_window(data);
	while (coord.y < WINDOW_HEIGHT)
	{
		coord.x = 0;
		while (coord.x < WINDOW_WIDTH)
		{
			new = complex_init(0, 0);
			old.r_part =  1.5 * (coord.x - WINDOW_WIDTH / 2) / (0.5 * zoom * WINDOW_WIDTH) + moveX;
			old.i_part =  (coord.y - WINDOW_HEIGHT / 2) / (0.5 * zoom * WINDOW_HEIGHT) + moveY;
			i = 0;
			while (i < MAX_ITERATIONS)
			{
				new = complex_addition(complex_square(new), old);
				if (((new.r_part * new.r_part) + (new.i_part * new.i_part)) > 4)
					break;
				i++;
			}
			if (i < MAX_ITERATIONS)
				mg_pixel_put(data, coord.x, coord.y, 0x00FFFFFF);
			coord.x++;
		}
		coord.y++;
	}
	mlx_put_image_to_window(data->data_buff.mlx_p, data->data_buff.win_p,
		data->data_buff.img_p, 0, 0);
	mlx_loop(data->data_buff.mlx_p);
}
