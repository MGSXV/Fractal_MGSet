/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:00:06 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/11 16:02:41 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	complex_init(t_complex *cn)
{
	cn->r_part = 0;
	cn->i_part = 0;
}

t_complex	complex_addition(t_complex cn1, t_complex cn2)
{
	t_complex	result;

	result.r_part = cn1.r_part + cn2.r_part;
	result.i_part = cn1.i_part + cn2.i_part;
	return (result);
}