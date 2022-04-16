/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:38:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 23:02:08 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_error_exit(char *err_msg, t_fractol *data, bool free)
{
	ft_printf("%s", err_msg);
	if (free)
		ft_free_all(data);
	exit(EXIT_FAILURE);
}

void	ft_free_all(t_fractol *data)
{
	if (data)
	{
		if (data->mlx_req.win_p && data->mlx_req.mlx_p)
			mlx_destroy_window(data->mlx_req.mlx_p, data->mlx_req.win_p);
		if (data->mlx_req.mlx_p)
			free(data->mlx_req.mlx_p);
		if (data->mlx_req.img_p)
			mlx_destroy_image(data->mlx_req.mlx_p, data->mlx_req.img_p);
		free(data);
	}
}
