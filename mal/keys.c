/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:56:16 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/08 18:32:05 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractal.h"

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == K_ESC)
	{
		end_fractol();
		return (0);
	}
	return 0;

}
