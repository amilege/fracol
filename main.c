/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:40:21 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/20 09:59:16 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "mlx/mlx.h"
  #include "fractal.h"
  #include <stdlib.h>
  #include <time.h>
#include <unistd.h>

int	t_close(int keycode, t_data *f)
{
	(void) keycode;
    mlx_destroy_window(f->mlx, f->mlx_win); 
	return (0);
}
int main(int argc, char **argv)
{
	t_data fractal;
    if (argc < 2)
      return 0;
    init_hook(&fractal, argv);
    return 0;
}

    /*
  write(1, "11", 2);
    clean_all(&fractal);
    
    write(1, "2", 1);
    printf("hace limipiar");
	init_fractal(&fractal, argv);
    printf("Hace initi");
	render(&fractal);
    write(1, "q", 1);
    printf("Hace render");

    //if (fractal.mlx_win == NULL)
     // write(1, "11", 2);
    //else
      //write(1, "w", 1);
  //no cal  mlx_loop_hook(fractal.mlx, &render, fractal.img);
    mlx_hook(fractal.mlx_win, EVENT_CLOSE_WIN, 0, end_fractol, &fractal);
	mlx_hook(fractal.mlx_win, 2, 0, key_hook, &fractal);
//    mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
    //mlx_hook(fractal.mlx_win, 2, 1L<<0, close, &fractal);
  	mlx_mouse_hook(fractal.mlx_win, mouse_event, &fractal);
    write(1, "11", 2);
    if (fractal.x)
      write(1, "err", 3);
    //printf("dedeode%d", fractal.x); 
    mlx_loop(fractal.mlx);
	//mlx_destroy_window(fractal->mlx, fractal->mlx_win);
    //free(fractal->addr);
   // free(fractal.mlx);
 //   free(fractal.mlx_win);
*/

