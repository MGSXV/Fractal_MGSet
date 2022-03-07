/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:10:34 by sel-kham          #+#    #+#             */
/*   Updated: 2022/03/05 04:26:33 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/fractol.h"

void	ft_router(char *flag)
{
	if (!ft_strncmp(flag, "-m", ft_strlen(flag)))
		ft_printf("Mandelbort set");
	else if (!ft_strncmp(flag, "-j", ft_strlen(flag)))
		ft_printf("Julia set");
	else if (!ft_strncmp(flag, "-s", ft_strlen(flag)))
		ft_printf("Something else");
	else
		ft_error_exit("Error: Invalid argument. \
Try \"--help\" for more information.\n");
}
