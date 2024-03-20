/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:29:16 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/20 11:33:49 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "mlx/mlx.h"
  #include "fractal.h"
  #include <stdlib.h>
  #include <time.h>
#include <unistd.h>

void init_hook(t_data *fractal, char **argv)
{
  // write(1, "11", 2);
    clean_all(fractal);

    //write(1, "2", 1);
    //printf("hace limipiar");
    init_fractal(fractal, argv);
    //printf("Hace initi");
    render(fractal);
    //write(1, "q", 1);
    //printf("Hace render");
    // write(1, "65", 2);
   //  printf("no entra l");
     //printf("\n1ro\n");
    //  printf("entra loop:%p, %p, %p, %p, %f\n\n", fractal->mlx, fractal->mlx_win, fractal->img, fractal->addr, fractal->min_real);
  
    mlx_hook(fractal->mlx_win, 2, 0, key_hook, fractal);
    //printf("\n2do\n");
    //printf("entra loop:%p, %p, %p, %p, %f\n\n", fractal->mlx, fractal->mlx_win, fractal->img, fractal->addr, fractal->min_real);
      
    mlx_hook(fractal->mlx_win, 4, 1L << 2, mouse_event, fractal);	

    //printf("\n3ro\n");
    //printf("entra loop:%p, %p, %p, %p, %f\n\n", fractal->mlx, fractal->mlx_win, fractal->img, fractal->addr, fractal->min_real);

     mlx_hook(fractal->mlx_win, EVENT_CLOSE_WIN, 0, t_close, fractal);
    mlx_loop(fractal->mlx);
    //mlx_destroy_window(fractal->mlx, fractal->mlx_win);
    //free(fractal->addr);
   // free(fractal.mlx);
 //   free(fractal.mlx_win);
 
} 
/*
//f (fractal.mlx_win == NULL)
     // write(1, "11", 2);
    //else
      //write(1, "w", 1);
  //no cal  mlx_loop_hook(fractal.mlx, &render, fractal.img);
  //  mlx_hook(fractal->mlx_win, EVENT_CLOSE_WIN, 0, t_close, fractal);
    mlx_hook(fractal->mlx_win, 2, 0, key_hook, fractal);
//    mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
    //mlx_hook(fractal.mlx_win, 2, 1L<<0, close, &fractal);
    mlx_mouse_hook(fractal->mlx_win, mouse_event, fractal);		
    //mlx_mouse_move(fractal->mlx_win, fractal->x, fractal->y);  
    write(1, "11", 2);
   // if (fractal.x)
   //   write(1, "err", 3);
    //printf("dedeode%d", fractal.x);
    mlx_loop(fractal->mlx);
    //mlx_destroy_window(fractal->mlx, fractal->mlx_win);
    //free(fractal->addr);
   // free(fractal.mlx);
 //   free(fractal.mlx_win);
 
*/
