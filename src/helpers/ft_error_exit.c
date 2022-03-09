/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:38:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/09 23:59:25 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_error_exit(char *err_msg, t_img_buff *data)
{
	ft_printf("%s", err_msg);
	if (data->data_buff.win_p)
		mlx_destroy_window(data->data_buff.mlx_p, data->data_buff.win_p);
	if (data->data_buff.mlx_p)
		free(data->data_buff.mlx_p);
	if (data->data_buff.img_p)
		mlx_destroy_image(data->data_buff.mlx_p, data->data_buff.img_p);
	exit(EXIT_FAILURE);
}
