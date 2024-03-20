/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintodo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:58:03 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/06 12:05:22 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractal.h"
#include <stdlib.h>
#include <time.h>
/*
typedef struct	s_data {
	void	*mlx;
	char	*name;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		*palette;
	int		color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_real;
	double	max_real;
	double	min_imagi;
	double	max_imagi;
}				t_data;
*/
void	clean_fractal(t_data *fractal)
{
	fractal->mlx=NULL;
	fractal->mlx_win=NULL;
	fractal->img=NULL;
	fractal->addr=NULL;
	fractal->palette=NULL;
	fractal->color=0;
	fractal->bits_per_pixel=-1;
	fractal->line_length=-1;
	fractal->endian=-1;
	fractal->min_real=0;
	fractal->max_real=0;
	fractal->min_imagi=0;
	fractal->max_imagi=0;

}
void	init_fractal(t_data *fractal, char **argv)
{

	int bits_per_pixel;
	int line_length;
	int endian;
	fractal->mlx=mlx_init();
	fractal->mlx_win=mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "FRACTOL");
	if (!fractal->mlx_win)
		exit (EXIT_FAILURE);
	fractal->img=mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
//		mlx_close_window(fractal->mlx_win);
		exit (EXIT_FAILURE);
	}
	fractal->addr=mlx_get_data_addr(fractal->img, &bits_per_pixel, &line_length, &endian);
}

void	init_data(t_data *fractal, char **argv)
{


	/*if (type_cmp(argv[1], "mandebrot"))
		fractal->name = JULIA;
	if (fractal->name == JULIA)
	{
		fractal->min_real=-2.0;
		fractal->max_real=2.0;
		fractal->min_imagi=-2.0;
		fractal->max_imagi= fractal->max_imagi + (fractal->max_real - fractal->min_real)*HEIGHT/WIDTH;
		return ;
	}*/
	fractal->min_real=-2.0;
	fractal->max_real=1.0;
	fractal->max_imagi=-1.5;
	fractal->min_imagi= fractal->max_imagi + (fractal->max_real - fractal->min_real)*HEIGHT/WIDTH;

}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int mandebrot(t_data *fractal, double y0, double x0 )
{
	double x;
	double y;
	int iteration;
	int max_iteration;
	int xtemp;
  x0 = x;// co-ordinate of pixel
  y0 = y;// co-ordinate of pixel

  x = 0;
  y = 0;
  iteration = 0;
  max_iteration = 1000;

  while ( x*x + y*y <= (2*2) && iteration < max_iteration )
  {
    xtemp = x*x - y*y + x0;
    y = 2*x*y + y0;
    
    x = xtemp;
    
    iteration = iteration + 1;
  }
  return iteration; 
}

int	calc_fractal(t_data *fractal, int x, int y)
{
	int it_num;
	it_num = 0;
	
	if (fractal->name == JULIA)
	{
		it_num=mandebrot(fractal, x, y);
	}

}
void draw_pixel_img()
{
 if ( iteration == max_iteration )
	  fractal->color = 0;
  pintar(x0,y0,fractal->color);
  else
	  fractal->color = iteration;
  pintar(x0,y0,fractal->color);

}
int render(t_data *img)
{
	int y;
	int x;
	int num_it;
//	i = 0;
/*	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			calc_fractal(x, y, )
			my_mlx_pixel_put(img, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);*/
	y = 0;
	//int col = rand();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			num_it = calc_fractal(x, y);
			draw_pixel_img(img, x, y, num_it);
		i//	my_mlx_pixel_put(img, y, x, col);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return 0;
	
}



int	check_args(int argc, char *arg1, char *arg2, char *arg3)
{
	if (argc <= 2 || argc > 4)
		return 1;
	return 0;
}
/*
void init_fractal(t_data *fractal)
{
	fractal->mlx = mlx_init();
	fractal->mlx_win = mlx_new_window(fractal->mlx, 1920, 1080, fractal->name);
	if (!fractal->mlx_win)
		exit (EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, 1920, 1080);
	if (!fractal->img)
	{
//		mlx_close_window(fractal->mlx_win);
		exit (EXIT_FAILURE);
	}


}

*/


int main(int argc, char **argv)
{
	t_data fractal;
	t_data img;
	void *mlx;
	void *mlx_win;

	if (check_args(argc, argv[1], argv[2], argv[3])==1)
		return 0;
	if (cpt ="mandebrot")
		fractal.name= "Mandebrot";
	set_fractal(&fractal);
	init_fractal(&fractal);
	init_data(&fractal, argv);
//	srand(time(0));
////	mlx = mlx_init();
	////mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	////img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//	&img.endian);
	img.mlx = mlx;
	img.mlx_win = mlx_win;
//	my_mlx_pxel_put(&img, 5,5, 0x00FF0000);
	mlx_loop_hook(mlx, pintar, &img);
	mlx_loop(mlx);

}



/*	int main(int argc, char **argv)
{
	t_data fractal;

	check_args(argv[1],argv[2], argv[3]);
	clean_all(&fractal);
	init_fractal(&fractal);
	init_data();
	init_win();
//	render();
	mlx_loop_hook(fractal.win, , &fractal);
	mlx_loop(fractal.win);
	terminate();
	exit();
	void *mlx;
	t_data img;
	void *mlx_win;
	
	if (argc == 4)
	{
		if (argv[1])
*/

