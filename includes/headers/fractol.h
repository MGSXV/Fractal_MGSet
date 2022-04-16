/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:16:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/16 21:36:59 by sel-kham         ###   ########.fr       */
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
# include<stdbool.h>

void		ft_error_exit(char *err_msg, t_fractol *data, bool free);
void		ft_free_all(t_fractol *data);
void		ft_free(t_img_buff *data);
void		ft_router(char *flag, t_fractol *data);
void		ft_init_data(t_fractol *data);

void		ft_fractol(t_fractol *data, void (*f)(t_fractol *data));
void		ft_mandelbrot(t_fractol *data);
void		ft_julia(t_fractol *data);
void		ft_burning_ship(t_fractol *data);

int			key_press_handler(int keycode, t_fractol *data);
int			mouse_press_handler(int keycode, int x, int y, t_fractol *data);
int			mouse_move_handler(int x, int y, t_fractol *data);
int			default_handler(t_fractol *data);
int			ft_close_window(t_fractol *data);
void		ft_color_handle(t_fractol *data);
void		ft_reset_fractal(t_fractol *data);
void		mg_pixel_put(t_fractol *data, int x, int y, unsigned int color);

t_complex	complex_addition(t_complex cn1, t_complex cn2);
t_complex	complex_init(double r_p, double i_p);
t_complex	complex_square(t_complex cn);

#endif