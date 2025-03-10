/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:45:33 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/04 16:46:03 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ship(double cr, double ci, t_fractol *fractol)
{
	double (zr), (zi), (tmp);
	int (iter);
	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < fractol->intesite)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = fabs(2 * zr * zi) + ci;
		zr = fabs(tmp);
		iter++;
	}
	return (iter);
}

void	draw_ship(t_fractol *fractol)
{
	int (x), (y), (iter);
	double (cr), (ci);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (x - WIDTH / 2.0) * (4.0 / WIDTH) 
				* fractol->zoom + fractol->move_x;
			ci = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) 
				* fractol->zoom + fractol->move_y;
			iter = ship(cr, ci, fractol);
			put_pixel(fractol, x, y, get_color(iter, fractol->intesite));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
