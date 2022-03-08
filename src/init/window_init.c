/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:12:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/08 08:25:27 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_init_data(t_data *data)
{
	data->mlx_p = mlx_init();
	if (!data->mlx_p)
		ft_error_exit("Could not initialize the MLX!\n", data);
	data->win_p = mlx_new_window(data->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol MGSet");
	if (!data->mlx_p)
		ft_error_exit("Could not initialize the windows!\n", data);
	data->img_p = mlx_new_image(data->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img_p)
		ft_error_exit("Could not initialize the windows!\n", data);
}

void	ft_new_window(t_data *data)
{
	ft_init_data(data);
	mlx_hook(data->win_p, ON_KEYDOWN, 0, ft_events_router, data);
	mlx_loop(data->mlx_p);
}