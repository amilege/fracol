/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:03:22 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/11 11:06:24 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
void    *ft_bzero(void *str, int  size)
{
        unsigned char   *str_str;
        int                  i;

        str_str = (unsigned char *)str;
        i = 0;
        while (i < size)
        {
                *str_str = '\0';
                str_str++;
                i++;
        }
        return (str);
}

void    *ft_calloc(int count, int size)
{
        void    *memory;

        memory = malloc(size * count);
        if (memory == 0)
                return (0);
        ft_bzero(memory, (size * count));
        return (memory);
}
