/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:10:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/10 17:18:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

int	ft_events_router(int keynum, t_img_buff *data)
{
	if (keynum == ESC_KEY)
		ft_close_window(data);
	return (0);
}

void	ft_router(char *flag, t_img_buff *data)
{
	if (!ft_strncmp(flag, "-m", ft_strlen(flag)))
		ft_mandelbrot(data);
	else if (!ft_strncmp(flag, "-j", ft_strlen(flag)))
		ft_printf("Julia set");
	else if (!ft_strncmp(flag, "-s", ft_strlen(flag)))
		ft_printf("Something else");
	else
		ft_error_exit("Error: Invalid argument. \
Try \"--help\" for more information.\n", data);
}
