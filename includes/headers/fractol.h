/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:16:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/08 23:26:15 by sel-kham         ###   ########.fr       */
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

void	ft_error_exit(char *err_msg, t_img_buff *data);
void	ft_free(t_img_buff *data);
void	ft_router(char *flag, t_img_buff *data);
void	ft_init_data(t_img_buff *data);
void	ft_new_window(t_img_buff *data);
void	ft_mandelbrot(t_img_buff *data);
int		ft_events_router(int keynum, t_img_buff *data);
int		ft_close_window(t_img_buff *data);

#endif