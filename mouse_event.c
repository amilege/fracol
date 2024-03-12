/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:51:01 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/10 19:39:55 by amile-ge         ###   ########.fr       */
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
    f->max_real -= center_re * direct;
    f->min_real -= center_re * direct;
  }
  else
  {
    f->max_real += center_re * direct;
    f->min_real += center_re * direct;

  }

}
int mouse_event(int key, t_data *f)
{
 // if (key == 1)
    //return 1;
  //if (key == 2)
   // return 2;
  //if (key == 3)
  //  return 3;
  if (key == MOUSE_UP)
   // move(f, 0.2, 'D');
//  if (key == 5)
  //  return 5;
    render(f);
    return 0;
}
