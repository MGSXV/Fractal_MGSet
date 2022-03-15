/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:39:15 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/15 23:28:31 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

char	*dec_to_hex(unsigned int num, int indecator)
{
	const char	*base;
	static char	*hex;

	base = "0123456789ABCDEF";
	hex = "";
	if (num < 16 && !indecator)
		hex = "0";
	indecator = 1;
	if (num > 15)
		dec_to_hex(num / 16, indecator);
	hex = ft_strjoin(hex, ft_substr(base, num % 16, 1));
	return (hex);
}

t_color	init_color(int r, int g, int b)
{
	t_color	color;

	if (r > 255 || r < 0)
		r = 0;
	if (g > 255 || g < 0)
		g = 0;
	if (b > 255 || b < 0)
		b = 0;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

char	*ft_rgb_to_hex(t_color color)
{
	char	*hex_color;

	hex_color = "0x";
	hex_color = ft_strjoin(hex_color, dec_to_hex(color.r, 0));
	hex_color = ft_strjoin(hex_color, dec_to_hex(color.g, 0));
	hex_color = ft_strjoin(hex_color, dec_to_hex(color.b, 0));
	return (hex_color);
}
