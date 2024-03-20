/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:40:21 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/13 11:44:18 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "mlx/mlx.h"
  #include "fractal.h"
  #include <stdlib.h>
  #include <time.h>

int	close(int keycode, t_data *f)
{
	mlx_destroy_window(f->mlx, f->mlx_win);
    exit(1);
//	return (0);
}
int main(int argc, char **argv)
{
	t_data fractal;
    if (argc < 2)
      return 0;
	clean_all(&fractal);
    printf("hace limipiar");
	init_fractal(&fractal, argv);
    printf("Hace initi");
	render(&fractal);
    printf("Hace render");

  //no cal  mlx_loop_hook(fractal.mlx, &render, fractal.img);
    mlx_hook(fractal.mlx_win, EVENT_CLOSE_WIN, 0, end_fractol, &fractal);
	mlx_key_hook(fractal.mlx_win, key_hook, &fractal);
//    mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
    //mlx_hook(fractal.mlx_win, 2, 1L<<0, close, &fractal);
  	mlx_mouse_hook(fractal.mlx_win, mouse_event, &fractal);

    mlx_loop(fractal.mlx);
	mlx_destroy_window(fractal.mlx, fractal.mlx_win);
    free(fractal.addr);

}
