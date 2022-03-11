/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:53:14 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/11 15:59:45 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "mlx.h"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

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
// bpp refers to bits per pixel
typedef struct __image_buffer__
{
	t_data	data_buff;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img_buff;

typedef struct s_complex
{
	double	r_part;
	double	i_part;
}	t_complex;

#endif