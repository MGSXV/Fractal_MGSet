/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_madelbrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:26:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/11 15:46:04 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_mandelbrot(t_img_buff *data)
{
	int	i;

	i = 100;
	ft_new_window(data);
	while (--i)
		mg_pixel_put(data, WINDOW_WIDTH / 2 - i, WINDOW_HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(data->data_buff.mlx_p, data->data_buff.win_p, data->data_buff.img_p, 0, 0);
	mlx_loop(data->data_buff.mlx_p);
}
