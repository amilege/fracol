 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:51:01 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/20 11:28:27 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractal.h"
#include <unistd.h>

//dividir un valor y sumarlo cuando haga zoom y vuando quiera no hacer zoom lo
//rsto
//
        /*   f->min_real =  f->min_real * zoomFactor ;
    f->/max_real = f->max_real * zoomFactor;
    f->min_imagi = f->min_imagi * zoomFactor ;
    f->max_imagi = f->max_imagi *zoomFactor;
    }
    //render(f);*/
int mouse_event(int key, t_data *f)
{
    write(1,"pup",3);
   // printf();
     printf("key:%p, %p, %p, %p, %f\n\n", f->mlx, f->mlx_win, f->img, f->addr, f->min_real);

/*
	long double	offset;
	long double	fast;

	fast = 0.5L;
	if (key ==  MOUSE_SCROLL_UP  || key ==  MOUSE_SCROLL_DOWN)
	{
		offset = 4L / (long double)WIDTH / f->zoom;
		f->x += ((long double)f->x - (long double)WIDTH / 2L)
			* offset;
		f->y += ((long double)HEIGHT / 2L - (long double)f->y)
			* offset;
	}
	if (key ==  MOUSE_SCROLL_UP)
		f->zoom *= fast;
	if (key ==  MOUSE_SCROLL_DOWN)
		f->zoom /= fast;
	if (key ==  MOUSE_SCROLL_UP|| key ==  MOUSE_SCROLL_DOWN)
		render(f);
    return 0;
*/
    double zoomFactor;
    double mouseRe;
    double mouseIm;
    if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
    { zoomFactor = 1.0;

        write(1, "1", 1);
        if (key == MOUSE_SCROLL_UP)
        {
            zoomFactor *= 2.0;
            write(1, "2", 1);
        }
        else if (key == MOUSE_SCROLL_DOWN)
        {
            zoomFactor /= 2.0;
            write(1, "3", 1);
        }
        mouseRe = (double)f->x / (WIDTH * (f->max_real - f->min_real)) + f->min_real;
        mouseRe = 2.5;
        //write(1, "4", 1);
        f->mlx = NULL;
        if (f->mlx_win == NULL)
            write(1, "error", 5);
        else
            write(1, "nose", 4);
        //printf("%f", f->max_real);
        mouseIm = (double)f->y / (HEIGHT * (f->max_imagi - f->min_imagi)) + f->min_imagi;
        //write(1, "4", 1);
        applyZoom(f, mouseRe, mouseIm, zoomFactor);
        //write(1, "5", 1);
    }
    render(f);
    write(1, "pupu", 4);
    printf("entra loop:%p, %p, %p, %p, %f", f->mlx, f->mlx_win, f->img, f->addr, f->min_real);
    return 0;
}

void applyZoom(t_data *f, double mouseRe, double mouseIm, double zoomFactor)
{
    double interpolation;

    interpolation = 1.0 / zoomFactor;
    f->min_real = interpolate(mouseRe, f->min_real, interpolation);
    f->max_real = interpolate(mouseRe, f->max_real, interpolation);
    f->min_imagi = interpolate(mouseIm, f->min_imagi, interpolation);
    f->max_imagi = interpolate(mouseIm, f->max_imagi, interpolation);
    printf("resultado de modificar el zoom %f", f->min_real);
}

double interpolate(double start, double end, double interpolation)
{
    printf("Entra en inter");
    return (start + ((end - start) * interpolation));

}
/*
int mouse_event(int key, t_data *f)
{
    double center_re = (f->min_real + f->max_real) / 2.0;
    if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
    {
    double center_re = (f->min_real + f->max_real) / 2.0;
        double range_re;
        double range_im;
        double zoom;

        zoom = 1.0;
        if (key == MOUSE_SCROLL_UP)
            zoom *= 2.0;
        range_re = (f->max_real - f->min_real) * zoom;
        range_im = (f->max_imagi - f->min_imagi) * zoom;
        f->max_real = f->x + range_re / 2;
        f->min_real = f->y - range_re / 2;
        f->max_imagi = f->x + range_im / 2;
        f->min_imagi = f->y - range_im / 2;    
    }
    render(f);
    return 0;
 

}*/
