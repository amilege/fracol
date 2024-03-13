/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:57:43 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/12 11:59:48 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "fractal.h"
#include <time.h>
#include "mlx/mlx.h"
#include <math.h>

int set_color (int iter)
{
  if (iter == MAX_ITER)
    return (0);
  else
  {
    int r;
    int g;
    int b;
    r = (int)(sin(0.05 * iter + 0)* 127 + 128);
    g = (int)(sin(0.05 * iter + 2)* 127 + 128);
    b = (int)(sin(0.05 * iter + 4)* 127 + 128);
//   printf("Iter: %d. r: %d, g: %d, b: %d", iter, r, g, b);
    return  (r << 16) | (g << 8) | b;
  }
}


void    set_pixel_color(t_data *fractal, int x, int y, int color, int it_num)
{
  int pos;

 fractal->addr[y * WIDTH*4 + x * 4 + 1] = color >> 8;
    fractal->addr[y * WIDTH*4 + x * 4 + 2] = color >> 16;
    fractal->addr[y * WIDTH*4 + x * 4  + 3] = color >> 24;
}
/*
  pos = (y * WIDTH + x)*4;

    fractal->addr[pos] =  (color & 0xFF0000) >> 16;
    fractal->addr[pos + 1]=  (color & 0x00FF00) >> 8;
    fractal->addr[pos + 2] =  color & 0x0000FF;
   // fractal->addr[pos + 3] =  (color & 0xFF000000) >> 24;
}


    fractal->addr[y * WIDTH*4 + x * 4 + 1] = color >> 8;
    fractal->addr[y * WIDTH*4 + x * 4 + 2] = color >> 16;
    fractal->addr[y * WIDTH*4 + x * 4  + 3] = color >> 24;
  
    fractal->addr[y * WIDTH*4 + x * 4] = color;
    fractal->addr[y * WIDTH*4 + x * 4 + 1] = color >> 8;
    fractal->addr[y * WIDTH*4 + x * 4 + 2] = color >> 16;
    fractal->addr[y * WIDTH*4 + x * 4  + 3] = color >> 24;

*/
   /* fractal->addr[y * WIDTH * 4 + x * 4] = color; // Corregido el cálculo de la
    fractal->addr[y * WIDTH * 4 + x * 4 + 1] = color >> 6;
    fractal->addr[y * WIDTH * 4 + x * 4 + 2] = color >> 12;
    fractal->addr[y * WIDTH * 4 + x * 4 + 3] = color >> 28;*/



 
 // if (it_num < 10)
   // my_mlx_pixel_put(fractal, x, y, rand()); 
 // else if (it_num >= 10 && it_num <= 20)
   // my_mlx_pixel_put(fractal, x, y, rand()); 
  //else if (it_num > 20 && it_num < 50)
   // my_mlx_pixel_put(fractal, x, y, rand()); 
 // else
  //  my_mlx_pixel_put(fractal, x, y, rand()); 

/*{
  if (color < 20)
    fractal->addr[x * 4 + y * WIDTH * 4] = color;
  else if (color < 50)
    fractal->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
  if (color < 70)
    fractal->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;

  if (color >= 70)
    fractal->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}*/
/*{ crec verde nuclear
  if (color < 50)
    fractal->addr[x * 4 + y * WIDTH * 4] = color;
  fractal->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 3;
  if (color < 70)
    fractal->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;

  if (color >= 70)
    fractal->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}*/
/*{ azul pastel
  int color_init;
  color_init = color;
  //if (color_init < 10)
    fractal->addr[x * 4 + y * WIDTH * 4] = color;
  fractal->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
  //if (color_init < 30)
    fractal->addr[x * 4 + y * WIDTH * 4 + 6] = color >> 16;

//  if (color_init < 5)
    fractal->addr[x * 4 + y * WIDTH * 4 + 7] = color >> 24;
}*/
/*{ lila
  int color_init;
  color_init = color;
  //if (color_init < 10)
    fractal->addr[x * 4 + y * WIDTH * 4] = color;
  fractal->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 8;
  //if (color_init < 30)
    fractal->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 16;

//  if (color_init < 5)
    fractal->addr[x * 4 + y * WIDTH * 4 + 6] = color >> 24;
}
{
  fractal->addr[x * 4 + y * WIDTH * 4] = color;
  fractal->addr[x * 4 + y * WIDTH * 4 +1] = color >> 8;
  fractal->addr[x * 4 + y * WIDTH * 4 +2] = color >> 16;
  fractal->addr[x * 4 + y * WIDTH * 4 +3] = color >> 24;
}*/








