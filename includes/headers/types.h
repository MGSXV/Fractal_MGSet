/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:53:14 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 21:37:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "mlx.h"

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_mlx
{
	void	*win_p;
	void	*mlx_p;
	void	*img_p;
}	t_mlx;

typedef struct s_screen
{
	int		window_width;
	int		window_height;
	int		max_iterations;
	double	zoom;
	double	move_x;
	double	move_y;
}	t_screen;

typedef struct s_color
{
	int	color;
	int	color_code;
}	t_color;
// bpp refers to bits per pixel
typedef struct __image_buffer__
{
	t_screen	screen;
	t_color		color;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img_buff;

typedef struct s_complex
{
	double	r_part;
	double	i_part;
}	t_complex;

typedef struct s_zoom
{
	int	max;
	int	min;
}	t_zoom;

typedef struct s_fractol
{
	t_mlx		mlx_req;
	t_coor		coord;
	t_complex	julia;
	t_complex	new;
	t_complex	old;
	t_complex	cons;
	t_zoom		zoom_in;
	t_zoom		zoom_out;
	t_img_buff	img_buff;
	t_color		color;
	double		center_x;
	double		center_y;
	int			iterations;
	int			max_iterations;
	double		x_scale;
	double		y_scale;
	int			value1;
	int			value2;
}	t_fractol;

#endif