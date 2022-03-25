/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 01:17:21 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/21 23:24:15 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

int	ft_zoomin(t_coor coord, t_img_buff *data)
{
	if (data)
		ft_printf("Zoom in : %d - %d\n", coord.x, coord.y);
	return (0);
}

int	ft_zoomout(t_coor coord, t_img_buff *data)
{
	if (data)
		ft_printf("Zoom out : %d - %d\n", coord.x, coord.y);
	return (0);
}
