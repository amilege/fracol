/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:43:24 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/13 10:53:10 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"
 #include "mlx/mlx.h"
void	clean_all(t_data *fractal)
{
  fractal->mlx=NULL;
      fractal->mlx_win=NULL;
      fractal->img=NULL;
      fractal->addr=NULL;
      fractal->palette=NULL;
      fractal->color=0;
      //fractal->bits_per_pixel=-1;
      //fractal->line_length=-1;
      //fractal->endian=-1;
      fractal->min_real=0;
      fractal->max_real=0;
      fractal->min_imagi=0;
      fractal->max_imagi=0;	
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
    mlx_destroy_image(fractal->mlx, fractal->img);
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
    fractal->mlx=mlx_init();
    fractal->mlx_win=mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "FRACTOL");
    if (!fractal->mlx_win)
        exit (EXIT_FAILURE);
    fractal->img=mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (!fractal->img)
    {
  //     mlx_close_window(fractal->mlx_win);
        exit (EXIT_FAILURE);
    }
    addr=mlx_get_data_addr(fractal->img, &bits_per_pixel, &line_length, &endian);
    fractal->addr = addr;
    fractal->bits_per_pixel = bits_per_pixel;
    fractal->line_length = line_length;
    fractal->endian =  endian;
    
}

void	set_fractal(t_data *fractal, char **argv)
{
	if (type_cmp(argv[1], "Mandebrot"))
    {
		fractal->name = MANDEBROT;
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
        fractal->max_real=2.0;
        fractal->min_imagi=-2.0;
        fractal->max_imagi= fractal->max_imagi + (fractal->max_real - fractal->min_real)*HEIGHT/WIDTH;
        return ;
	}
	fractal->min_real=-2.0;
    fractal->max_real=2.0;
    fractal->max_imagi=-2.0;
    fractal->min_imagi= fractal->max_imagi + (fractal->max_real - fractal->min_real)*HEIGHT/WIDTH;

}

void	init_fractal(t_data *fractal, char **argv)
{
	init_win(fractal);
	set_fractal(fractal, argv);
	data_fractal(fractal);
}
