/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:40:21 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/08 18:10:04 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "mlx/mlx.h"
  #include "fractal.h"
  #include <stdlib.h>
  #include <time.h>


int main(int argc, char **argv)
{
	t_data fractal;
    if (argc < 1)
      return 0;
	clean_all(&fractal);
    printf("hace limipiar");
	init_fractal(&fractal, argv);
    printf("Hace initi");
	render(&fractal);
    printf("Hace render");
    mlx_hook(fractal.mlx_win, EVENT_CLOSE_WIN, 0, end_fractol, &fractal);
	mlx_key_hook(fractal.mlx_win, key_hook, &fractal);
   // mlx_hook(vars.win, 2, 1L<<0, close, &vars);
   	mlx_mouse_hook(fractal.mlx_win, mouse_event, &fractal);
    //mlx_loop_hook(fractal.mlx, render(&fractal), fractal.img);
    mlx_loop(fractal.mlx);

}
