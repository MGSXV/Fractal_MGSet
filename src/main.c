/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:28:53 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/08 23:25:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/fractol.h"

int	main(int c, char **v)
{
	char		*flag;
	t_img_buff	data;

	flag = "--help";
	if (c != 2)
		ft_error_exit("Error: No valid argument was provided.\
Try \"--help\" for more information.\n", &data);
	if (!ft_strncmp(v[1], flag, ft_strlen(flag)))
	{
		ft_printf("Here are the available options:\
\n\t[*] Mandelbrot set (-m)\n\t[*] Julia set (-j)\
\n\t[*] Some other Fractal here (-s)\n");
		exit(EXIT_SUCCESS);
	}
	else
		ft_router(v[1], &data);
	return (0);
}
