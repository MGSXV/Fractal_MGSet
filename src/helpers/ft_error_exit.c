/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:38:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/08 08:27:38 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_error_exit(char *err_msg, t_data *data)
{
	ft_printf("%s", err_msg);
	if (data->win_p)
		mlx_destroy_window(data->mlx_p, data->win_p);
	if (data->mlx_p)
		free(data->mlx_p);
	exit(EXIT_FAILURE);
}