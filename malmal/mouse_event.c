 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:51:01 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/13 12:02:26 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractal.h"
/*
void  move(t_data *f, double direct, char type)
{
  int center_re;
  int center_im;
  center_re = f->max_real-f->min_real;
  center_im = f->max_imagi-f->min_imagi;
  if (type == 'D')
  {
    f->max_real -= center_re * direct;
    f->min_real -= center_re * direct;
  }
  else if (type == 'P')
  {
    f->max_real += center_re * direct;
    f->min_real += center_re * direct;

  }
}*/

//dividir un valor y sumarlo cuando haga zoom y vuando quiera no hacer zoom lo
//rsto
int mouse_event(int key, t_data *f)
{
 // if (key == 1)
    //return 1;
  //if (key == 2)
   // return 2;
  //if (key == 3)
  //  return 3;
  //if (key == MOUSE_UP)
    //move(f, 0.2, 'U');
  //if (key == MOUSE_DOWN)
    //move(f, -0.2, 'D');
   
      // reinit(f);
    //render(f);
    return 0;
}
