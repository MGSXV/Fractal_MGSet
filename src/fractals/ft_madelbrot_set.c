/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madelbrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:26:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/11 20:23:05 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

int	draw_mandelbrot(void)
{
	static int	iterations;
	t_complex	old_z;
	t_complex	new_z;
	t_complex	con;

	if (iterations == 0)
	{
		old_z = complex_init(0, 0);
		new_z = complex_init(0, 0);
	}
	return (0);
}

void	ft_mandelbrot(t_img_buff *data)
{
	t_coor		coor;
	int			max_iterations;

	coor.y = 0;
	mg_pixel_put(data, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(data->data_buff.mlx_p, data->data_buff.win_p,
		data->data_buff.img_p, 0, 0);
	mlx_loop(data->data_buff.mlx_p);
}
