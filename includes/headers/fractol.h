/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:16:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/16 16:23:24 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "types.h"
# include "macos_keys.h"
# include "mlx.h"
# include<math.h>

void		ft_error_exit(char *err_msg, t_img_buff *data);
void		ft_free(t_img_buff *data);
void		ft_router(char *flag, t_img_buff *data);
void		ft_init_data(t_img_buff *data);
void		ft_new_window(t_img_buff *data);
void		ft_mandelbrot(t_img_buff *data);
int			ft_events_router(int keynum, t_img_buff *data);
int			ft_close_window(t_img_buff *data);
void		mg_pixel_put(t_img_buff *data, int x, int y, unsigned int color);
t_complex	complex_addition(t_complex cn1, t_complex cn2);
t_complex	complex_init(double r_p, double i_p);
t_complex	complex_square(t_complex cn);
int         ft_color_handle(int color, int i);

#endif