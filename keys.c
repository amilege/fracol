/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:56:16 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/13 11:58:39 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractal.h"
 void  move(t_data *f, double direct, char type)
{
  int center_re;
  int center_im;
  center_re = f->max_real-f->min_real;
  center_im = f->max_imagi-f->min_imagi;
  if (type == 'D')
  {
    f->max_imagi += center_re * direct;
    f->min_imagi += center_re * direct;
  }
  else if (type == 'U')
  {
    f->max_imagi += center_re * direct;
    f->min_imagi += center_re * direct;

  }
  else if (type == 'R')
  {
    f->max_real += center_re * direct;
    f->min_real += center_re * direct;

  }
  else if (type == 'L')
  {
    f->max_real += center_re * direct;
    f->min_real += center_re * direct;

  }
}
int	key_hook(int keycode, t_data *f)
{
	if (keycode == K_ESC)
	{
		end_fractol();
	//	mlx_destroy_window(f->mlx, f->mlx_win);
		return (0);
	}
 	else if (keycode == KEY_UP)
    	move(f, -0.2, 'U');
	else if (keycode == KEY_DOWN)
    	move(f, 0.2, 'D');
	else if (keycode == KEY_RIGHT)
    	move(f, 0.2, 'R');
	else if (keycode == KEY_LEFT)
    	move(f, -0.2, 'L');
	//else
	//	return(1);
	render(f);
	return 0;

}
