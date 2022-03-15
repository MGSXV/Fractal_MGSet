/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:53:14 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/15 17:30:43 by sel-kham         ###   ########.fr       */
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

typedef struct s_data
{
	void	*win_p;
	void	*mlx_p;
	void	*img_p;
}	t_data;

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
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;
// bpp refers to bits per pixel
typedef struct __image_buffer__
{
	t_data		data_buff;
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

#endif