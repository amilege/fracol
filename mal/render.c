/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:10:07 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/12 11:56:44 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
#include <time.h>

int calc_fractal(t_data *fractal, double x, double y)
{
      int it_num;

   //   it_num = 0;
      //if (fractal->name == MANDEBROT)
      //{
          it_num=mandebrot(fractal, x, y);
     // }
      return (it_num);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    render(t_data *fractal)
{
    double x;
    double  y;
    double c_re;
    double c_im;
    double re_factor;
    double im_factor;
    int it_num;
    re_factor = (fractal->max_real-fractal->min_real)/(WIDTH-1);
    im_factor = (fractal->max_imagi-fractal->min_imagi)/(HEIGHT-1);
    mlx_clear_window(fractal->mlx, fractal->mlx_win);
    y = 0;
    while (y < HEIGHT)
    {
          c_im = fractal->max_imagi - y*im_factor;
          x = 0;
          while (x < WIDTH)
          {
            c_re = fractal->min_real + x*re_factor;
            it_num = calc_fractal(fractal, c_re, c_im);
            set_pixel_color(fractal, x, y, rand(), it_num);
         //   draw_pixel_img(fractal->img, x, y, it_num);

            x++;

          }
          y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);

}
/*{
    int x;
    int  y;
    double c_re;
    double c_im;
    double re_factor;
    double im_factor;
    int color;
    int it_num;
    x =0;
    y=0;

    while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            c_re = fractal->min_real + (double)x * (fractal->max_real - fractal->min_real) / WIDTH;
            c_im = fractal->max_imagi - (double)y * (fractal->max_imagi - fractal->min_imagi) / HEIGHT;
            it_num = mandebrot(fractal, c_re, c_im);
            printf("\n\nel it ees: %d\n\n\n", it_num);
            color = set_color(it_num);
            set_pixel_color(fractal, y, x, color, it_num);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
}





  //  re_factor = (fractal->max_real-fractal->min_real)/(WIDTH-1);
    //im_factor = (fractal->max_imagi-fractal->min_imagi)/(HEIGHT-1);
    mlx_clear_window(fractal->mlx, fractal->mlx_win);
    y = 0;
    x= 0;
    while (y < HEIGHT)
    {
      x = 0;
      while (x < WIDTH)
      {
       // c_re = fractal->min_real + (double)x*re_factor;
      //  c_im = fractal->max_imagi - (double)y*im_factor;
        c_im = (y - HEIGHT / 2.0) * 4.0/ HEIGHT;     
        c_re = (x - WIDTH / 2.0) * 4.0/ WIDTH;
        it_num = calc_fractal(fractal, c_re, c_im);
       // color = set_color(it_num);
       // set_pixel_color(fractal,y, x, color, it_num);          
      if (it_num > 0)
          set_pixel_color(fractal, x, y, 0x00FF0000 , it_num);
        x++;
      }
      y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);

}*/

 //    c_re = fractal->min_real + (double)x * (fractal->max_real - fractal->min_real) / WIDTH;
	//	c_im = fractal->max_imagi + (double)y * (fractal->min_imagi - fractal->max_imagi) / HEIGHT;

     /*     //  mlx_pixel_put(fractal->mlx, fractal->mlx_win, x, y, rand());
            printf("%i\n", it_num);
          set_pixel_color(fractal, x, y, fractal->palette[it_num], it_num);
     //     if (it_num > 0)
       //    set_pixel_color(fractal, x, y,  fractal->palette[it_num] , it_num);
      //    if (it_num > 2)
        //    set_pixel_color(fractal, x, y,   fractal->palette[it_num]  , it_num);
        //  if (it_num > 4)
          //  set_pixel_color(fractal, x, y,  fractal->palette[it_num] , it_num);
       //    set_pixel_color(fractal, x, y, fractal->palette[it_num], it_num);
        //   else
      //    set_pixel_color(fractal, x, y, 0x00FF0000 , it_num);

           // draw_pixel_img(fractal->img, x, y, it_num);
           //
          //  if (it_num > 0)
           //   my_mlx_pixel_put(fractal, x, y , fractal->palette[it_num]);
//              my_mlx_pixel_put(fractal, x, y , 0x00FF0000);

           // my_mlx_pixel_put(fractal, x, y , 0);*/
