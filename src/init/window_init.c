/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:12:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 21:50:06 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_init_data(t_fractol *data)
{
	data->mlx_req.mlx_p = mlx_init();
	if (!data->mlx_req.mlx_p)
		ft_error_exit("Could not initialize the MLX!\n", data, true);
	data->mlx_req.win_p = mlx_new_window(data->mlx_req.mlx_p,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol MGSet");
	if (!data->mlx_req.win_p)
		ft_error_exit("Could not initialize the windows!\n", data, true);
	data->mlx_req.img_p = mlx_new_image(data->mlx_req.mlx_p,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx_req.img_p)
		ft_error_exit("Could not initialize the windows!\n", data, true);
	data->img_buff.addr = mlx_get_data_addr(data->mlx_req.img_p,
			&data->img_buff.bpp, &data->img_buff.line_len,
			&data->img_buff.endian);
	data->x_scale = 4.0 / WINDOW_WIDTH;
	data->y_scale = 4.0 / WINDOW_HEIGHT;
	data->center_x = 2.0;
	data->center_y = 2.0;
	data->max_iterations = 50;
	data->color.color = 0xf4f4f5;
	data->color.color_code = 0;
}
