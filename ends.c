/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:27 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/08 18:03:29 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
int  end_fractol(int keycode, t_data *f)
{
  mlx_destroy_window(f->mlx, f->mlx_win);
  return (0); 
}


