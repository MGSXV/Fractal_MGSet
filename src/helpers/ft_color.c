/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:39:15 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/16 21:39:34 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

int ft_color_handle(int color, int i)
{
	int red;
	int green;
	int blue;

	red = ((color / (16 * 16 * 16 * 16) * i * 50) %256);
	green = ((color - (red * 16 * 16 * 16 * 16) * i * 50) %256 / (16 * 16));
	blue = ((color - (red * 16 * 16 * 16 * 16)) - (green * 16 * 16) * i * 50) % 256;
	return ((red * 16 * 16 * 16 * 16) + (green * 16 * 16) + blue);
}
