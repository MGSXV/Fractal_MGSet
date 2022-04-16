/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mg_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:40:46 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 21:41:52 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	mg_pixel_put(t_fractol *data, int x, int y, unsigned int color)
{
	char	*dst;

	if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
		return ;
	dst = data->img_buff.addr + (y * data->img_buff.line_len
			+ x * (data->img_buff.bpp / 8));
	*(unsigned int *)dst = color;
}
