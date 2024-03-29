/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:56:16 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/20 10:34:03 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractal.h"
 void  move(t_data *f, double direct, char type)
{
  double center_re;
  double center_im;
  center_re = f->max_real-f->min_real;
  center_im = f->max_imagi-f->min_imagi;
  if (type == 'D')
  {
    f->max_imagi += center_im * direct;
    f->min_imagi += center_im * direct;
  }
  else if (type == 'U')
  {
    f->max_imagi += center_im * direct;
    f->min_imagi += center_im * direct;

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
void  zoom(t_data *f, double zoom, char type)
{
    double center_re; 
    double center_im;
    double range_re;
    double range_im;

    center_re = (f->min_real + f->max_real) / 2.0;
    center_im = (f->min_imagi + f->max_imagi) / 2.0;
    range_re = (f->max_real - f->min_real) / 2.0;
    range_im = (f->max_imagi - f->min_imagi) / 2.0;
    f->min_real = center_re - range_re * zoom;
    f->max_real = center_re + range_re * zoom;
    f->min_imagi = center_im - range_im * zoom;
    f->max_imagi = center_im + range_im * zoom;
}

  /*

    double center_re;
    double center_im;

    center_re = (f->min_real-f->max_real)  ;
    center_im = (f->max_imagi-f->min_imagi) ;
   // center_im *= 0.8;
    f->min_real = f->max_real + zoom * center_re;
    f->max_real = f->max_real + (center_re - zoom * center_re)/2;
    f->min_imagi = f->min_imagi  + ( center_im - zoom * center_im)/2;
    f->max_imagi = f->min_imagi + zoom * center_im;
  */

int	key_hook(int keycode, t_data *f)
{

	if (keycode == K_ESC)
	{
		end_fractol();
	//	mlx_destroy_window(f->mlx, f->mlx_win);
		return (0);
	}
    else if (keycode == KEY_MINUS)
      zoom(f, 2.0, 'U');
    else if (keycode == KEY_PLUS)
      zoom(f, 0.5, 'D');

 	else if (keycode == KEY_UP)
    	move(f, 0.2, 'U');
	else if (keycode == KEY_DOWN)
    	move(f, -0.2, 'D');
	else if (keycode == KEY_RIGHT)
    	move(f, 0.2, 'R');
	else if (keycode == KEY_LEFT)
    	move(f, -0.2, 'L');
	else
		return(1);

	render(f);
	printf("key:%p, %p, %p, %p, %f\n\n", f->mlx, f->mlx_win, f->img, f->addr, f->min_real);
    return 0;

}
