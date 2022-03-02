/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:19:37 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/02 00:44:19 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<math.h>
# include<stdlib.h>
# include"mlx.h"
# include"./ft_printf/ft_printf.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

void	ft_error(char *err_msg);

#endif