/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mg_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:40:46 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/11 15:46:27 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	mg_pixel_put(t_img_buff *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8)); // you can instead write 4 instead of (data->bpp / 8), I guess
	*(unsigned int *)dst = color;
}