/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:06:07 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/12 10:08:27 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HEIGHT	600
#define WIDTH	800
#define JULIA	0
#define MANDEBROT 1
#define MAX_ITER 100
#define EVENT_CLOSE_WIN 17
#define K_ESC 53
#define MOUSE_UP 4
#define MOUSE_DOWN 5

typedef struct	s_data {
	void	*mlx;
	int 	name;
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

void	clean_all(t_data *fractal);
void	init_fractal(t_data *fractal, char **argv);
void	render(t_data *fractal);
int		mandebrot(t_data *fractal, double y0, double x0);
void    set_pixel_color(t_data *fractal, int x, int y, int color, int it_num);
int		key_hook(int keycode, t_data *vars);
int		end_fractol();
int		mouse_event(int key, t_data *f);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		set_color (int iter);
void    init_win(t_data *fractal);
void    *ft_calloc(int count, int size);
#endif
