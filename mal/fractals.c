/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:16:44 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/12 12:06:35 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
int mandebrot(t_data *fractal, double c_re, double c_im )// c_re = x0, c_im = y0
{
    double z_re;
    double z_im;
    double x;
    double y;
    double z;
    int iteration;
    int max_iteration;
    double x0;
    double y0;
    double z_re2; //xtemp;
    z_re = c_re;
    z_im = c_im; // z = ci
    x0 = c_re;// co-ordinate of pixel
    y0 = c_im;// co-ordinate of pixel

    x = 0;
    y = 0;

    iteration = 0;
    max_iteration = 100;

    while (iteration < MAX_ITER)
    {
        if (z_re*z_re + z_im*z_im > (2*2))
            return (iteration);

    //while(z_rei*z_re + z_im*z_im >= (2*2) && iteration <= MAX_ITER)

        z_re2 = z_re*z_re - z_im*z_im + c_re;
        z_im = 2*z_re*z_im + c_im;
        z_re = z_re2;
        iteration = iteration + 1;
    }
    return (iteration);
}

    /*{
    double z_re;
    double z_im;
    double temp;
    int iteration;
    iteration = 0;
    z_re = 0;
    z_im = 0;
    while (iteration < MAX_ITER)
    {
        if ((z_re*z_re + z_im*z_im) > (2*2))
            break ;

        temp = z_re*z_re - z_im*z_im + c_re;
        z_im = 2*z_re*z_im + c_im;
        z_re = temp;
        iteration = iteration + 1;
    }
    return (iteration);
}




{
    double z_re;
    double z_im;
    double temp;
    int iteration;
    iteration = 0;
    z_re = 0;
    z_im = 0;

    while ((z_re * z_re + z_im * z_im) < (2 * 2) && iteration < MAX_ITER) 
    {
        if ((z_re*z_re + z_im*z_im) > (2*2))
            break ;
        double temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = temp;
        iteration++;
    }
    printf("\nEl iter final es: %d\n", iteration);
    return iteration;
}


    while (iteration < MAX_ITER)
    {
        if ((z_re*z_re + z_im*z_im) > (2*2))
            break ;

        temp = z_re*z_re - z_im*z_im + c_re;
        z_im = 2*z_re*z_im + c_im;
        z_re = temp;
        iteration = iteration + 1;
    }
    return (iteration);*/

    /*
    double y;
    double z;

    int max_iteration;
    double x0;
    double y0;
    double z_re2; //xtemp;
    z_re = c_re;
    z_im = c_im; // z = ci
    x0 = c_re;// co-ordinate of pixel
    y0 = c_im;// co-ordinate of pixel

    x = 0;
    y = 0;

    iteration = 0;
    max_iteration = 100;

    while (iteration < MAX_ITER)
    {
        if (z_re*z_re + z_im*z_im > (2*2))
            return (iteration);
    
    //while(z_rei*z_re + z_im*z_im >= (2*2) && iteration <= MAX_ITER)
    
        z_re2 = z_re*z_re - z_im*z_im + c_re;
        z_im = 2*z_re*z_im + c_im;
        z_re = z_re2;
        iteration = iteration + 1;
    }
    return (0);
*/
/*    while ( x*x + y*y <= (2*2) && iteration < max_iteration )
    {
     z = x*x - y*y + x0;
      y = 2*x*y + y0;

      x = z;

      iteration = iteration + 1;
    }
    return iteration;
*/
/*
    int	mandebrot(t_data *fractal, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

*/
