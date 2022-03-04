/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:28:53 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/04 22:26:45 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/fractol.h"

int	main(int c, char *v)
{
	if (c < 2)
		ft_error_exit("Error: No valid arguments were provided. try \"--help\" for more information.\n");
	if (ft_strncmp(v[1], "--help", 6))
	{
		ft_printf("Here are the available options:\n\t[*]\tMandelbrot set\n\t[*] Julia set\n\t[*] Some other Fractal here\n");
		exit(EXIT_SUCCESS);
	}
}