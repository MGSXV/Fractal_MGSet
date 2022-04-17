/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:28:53 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/17 01:06:50 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/fractol.h"

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_p = NULL;
	mlx->win_p = NULL;
	mlx->img_p = NULL;
}

static int	check_args(int c, char **v, t_fractol *fractol)
{
	char	*flag;

	flag = "--help";
	if (c != 2)
		ft_error_exit("Error: No valid argument was provided. \
Try \"--help\" for more information.\n", fractol, true);
	else if (!ft_strncmp(v[1], flag, ft_strlen(flag)))
	{
		ft_error_exit("Here are the available options:\
\n\t[*] Mandelbrot set (-m)\n\t[*] Julia set (-j)\
\n\t[*] Some other Fractal here (-s)\n", fractol, true);
	}
	return (1);
}

int	main(int c, char **v)
{
	t_fractol	*fractol;

	fractol = (t_fractol *) malloc(sizeof(t_fractol));
	if (!fractol)
		ft_error_exit("Unkown error!", fractol, true);
	init_mlx(&(fractol->mlx_req));
	if (check_args(c, v, fractol))
	{
		ft_init_data(fractol);
		ft_router(v[1], fractol);
		mlx_key_hook(fractol->mlx_req.win_p, &key_press_handler, fractol);
		mlx_hook(fractol->mlx_req.win_p, DESTROY_NOTIFY, 0,
			&ft_close_window, fractol);
		mlx_hook(fractol->mlx_req.win_p, 4, 0, &mouse_press_handler, fractol);
		mlx_hook(fractol->mlx_req.win_p, 6, 0, &mouse_move_handler, fractol);
		mlx_loop_hook(fractol->mlx_req.mlx_p, &default_handler, fractol);
		mlx_loop(fractol->mlx_req.mlx_p);
	}
	return (0);
}
