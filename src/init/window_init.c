/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:12:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/08 23:29:24 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_init_data(t_img_buff *data)
{
	data->data_buff->mlx_p = mlx_init();
	if (!data->data_buff->mlx_p)
		ft_error_exit("Could not initialize the MLX!\n", data);
	data->data_buff->win_p = mlx_new_window(data->data_buff->mlx_p,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol MGSet");
	if (!data->data_buff->win_p)
		ft_error_exit("Could not initialize the windows!\n", data);
	data->data_buff->img_p = mlx_new_image(data->data_buff->mlx_p,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->data_buff->img_p)
		ft_error_exit("Could not initialize the windows!\n", data);
}

void	ft_new_window(t_img_buff *data)
{
	ft_init_data(data);
	mlx_hook(data->data_buff->win_p, ON_KEYDOWN, 0, ft_events_router, data);
	mlx_loop(data->data_buff->mlx_p);
}
