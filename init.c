/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:43:24 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/20 11:23:55 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"
 #include "mlx/mlx.h"
void	clean_all(t_data *fractal)
{

    //fractal->mlx=NULL;
      write(1, "0", 1);
      //fractal->mlx_win=NULL;
      fractal->img=NULL;
      write(1, "0", 1);
      fractal->addr=NULL;
      fractal->palette=NULL;
      fractal->color=-1;
      //fractal->bits_per_pixel=-1;
      //fractal->line_length=-1;
      //fractal->endian=-1;
      fractal->min_real=0;
      fractal->max_real=0;
      fractal->min_imagi=0;
      fractal->max_imagi=0;
      fractal->x=0;
      fractal->y=0;
}

int type_cmp(char *nom, char *compar)
{
    int i;
    i = 0;

    while (nom[i] != '\0')
    {
        if (nom[i] != compar[i])
            return 0;
        i++;
    }
    return 1;
}

void  reinit(t_data *fractal)
{
  //if (fractal->palette)
 //   free(fractal->palette);
  if (fractal->mlx && fractal->img)
    mlx_destroy_image(fractal->mlx, fractal->mlx_win);
  if (fractal->addr)
    fractal->addr = NULL;
  init_win(fractal);
}

void	init_win(t_data *fractal)
{
	int bits_per_pixel;
    int line_length;
    int endian; 
    char *addr;
  //  fractal->palette = malloc((MAX_ITER + 1)*sizeof(int));
   //fractal->palette = ft_calloc((MAX_ITER + 1),sizeof(int));
   //if (fractal->palette[MAX_ITER + 1] != '\0')
    //fractal->palette[MAX_ITER + 1] = '\0';
    fractal->mlx= mlx_init();
    write(1, "si", 2);
    fractal->mlx_win=mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "FRACTOL");
    if (!fractal->mlx_win)
        exit (EXIT_FAILURE);
    fractal->img=mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (!fractal->img)
    {
      mlx_destroy_window(fractal->mlx_win, fractal->mlx_win);
      exit(EXIT_FAILURE);
    }
    fractal->addr=mlx_get_data_addr(fractal->img, &bits_per_pixel, &line_length, &endian);
    //fractal->addr = addr;
    fractal->bits_per_pixel = bits_per_pixel;
    fractal->line_length = line_length;
    fractal->endian =  endian;
    
}

void	set_fractal(t_data *fractal, char **argv)
{
	if (type_cmp(argv[1], "Mandelbrot"))
    {
		fractal->name = MANDELBROT;
        printf("entra");
    }
	else if(type_cmp(argv[1], "Julia"))
		fractal->name = JULIA;
    else
    {
        printf("incorrecto");
        exit(1);

    }
}

void	data_fractal(t_data *fractal)
{
	if (fractal->name == JULIA)
	{
		fractal->min_real=-2.0;
        fractal->max_real=1.5;
        fractal->min_imagi=-2.0;
        fractal->max_imagi= fractal->max_imagi + (fractal->max_real - fractal->min_real)*HEIGHT/WIDTH;
        fractal->zoom = 200;
        return ;
	}
	fractal->min_real=-2.0;
    fractal->max_real=2.0;
    fractal->max_imagi=-2.0;
    fractal->zoom = 200;
    fractal->min_imagi= fractal->max_imagi + (fractal->max_real - fractal->min_real)*HEIGHT/WIDTH;
    printf("val: %d", fractal->x);
}

void	init_fractal(t_data *fractal, char **argv)
{
   // write(1, "33", 2);
	init_win(fractal);
    //write(1, "44", 2);
	set_fractal(fractal, argv);
   // write(1, "55", 2);
	data_fractal(fractal);
   // write(1, "66", 2);
   // printf("%p, %p, %p, %p, %f", fractal->mlx, fractal->mlx_win, fractal->img, fractal->addr, fractal->min_real);
}
