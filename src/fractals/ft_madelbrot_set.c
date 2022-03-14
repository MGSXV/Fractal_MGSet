/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madelbrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:26:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/14 23:20:47 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

static int	calculate_mandelbrot(t_coor *coord)
{
	t_complex	z;
	t_complex	c;
	int			iteration_numb;
	t_zoom		z_xy;

	z_xy.zoom = 1;
	z_xy.move_x = -.5;
	z_xy.move_y = 0;
	iteration_numb = 0;
	z = complex_init(0, 0);
	c.r_part = 1.5 * (coord->x - WINDOW_WIDTH / 2) / (0.5 * z_xy.zoom * WINDOW_WIDTH) + z_xy.move_x;
	c.i_part = (coord->y - WINDOW_HEIGHT / 2) / (0.5 * z_xy.zoom * WINDOW_HEIGHT) + z_xy.move_y;
	while (iteration_numb < MAX_ITERATIONS)
	{
		z = complex_addition(complex_square(z), c);
		if (((z.r_part * z.r_part) + (z.i_part * z.i_part)) > 4)
			break ;
		iteration_numb++;
	}
	return (iteration_numb);
}

void	ft_mandelbrot(t_img_buff *data)
{
	t_coor		coord;
	int			i;

	coord.y = 0;
	ft_new_window(data);
	while (coord.y < WINDOW_HEIGHT)
	{
		coord.x = 0;
		while (coord.x < WINDOW_WIDTH)
		{
			i = calculate_mandelbrot(&coord);
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
