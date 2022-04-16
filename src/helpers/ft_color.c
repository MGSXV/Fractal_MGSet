/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:39:15 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 21:40:20 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_color_handle(t_fractol *data)
{
	data->color.color_code++;
	if (data->color.color_code == 0)
		data->color.color = 0xff0801;
	else if (data->color.color_code == 1)
		data->color.color = 0xfff600;
	else if (data->color.color_code == 2)
		data->color.color = 0x18ff00;
	else if (data->color.color_code == 3)
		data->color.color = 0xf4f4f5;
	else if (data->color.color_code == 4)
		data->color.color = 0xb0ffd9;
	else if (data->color.color_code == 5)
		data->color.color_code = 0;
}
