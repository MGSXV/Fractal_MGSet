/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:00:06 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/11 20:21:24 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

t_complex	complex_init(double r_p, double i_p)
{
	t_complex	result;

	result.r_part = r_p;
	result.i_part = i_p;
	return (result);
}

t_complex	complex_addition(t_complex cn1, t_complex cn2)
{
	t_complex	result;

	result.r_part = cn1.r_part + cn2.r_part;
	result.i_part = cn1.i_part + cn2.i_part;
	return (result);
}

t_complex	complex_square(t_complex cn)
{
	t_complex	result;

	result = complex_init(pow(cn.r_part, 2) - pow(cn.i_part, 2),
			2 * cn.r_part * cn.i_part);
	return (result);
}
