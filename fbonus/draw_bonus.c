/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:55:07 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/10 17:16:39 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	offset;

	offset = (y * fractol->line_len) + (x * (fractol->bpp / 8));
	*(unsigned int *)(fractol->addr + offset) = color;
}

int	mandelbrot(double cr, double ci, t_fractol *fractol)
{
	double (zr), (zi), (tmp);
	int (iter);
	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < fractol->intesite)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_fractol *fractol)
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
			iter = mandelbrot(cr, ci, fractol);
			put_pixel(fractol, x, y, get_color(iter, fractol->intesite));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

int	julia(double zr, double zi, t_fractol *fractol)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < fractol->intesite)
	{
		tmp = zr * zr - zi * zi + fractol->julia_cr;
		zi = 2 * zr * zi + fractol->julia_ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_fractol *fractol)
{
	int (x), (y), (iter);
	double (zr), (zi);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zr = (x - WIDTH / 2.0) * (4.0 / WIDTH) 
				* fractol->zoom + fractol->move_x;
			zi = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) 
				* fractol->zoom + fractol->move_y;
			iter = julia(zr, zi, fractol);
			put_pixel(fractol, x, HEIGHT - y - 1, 
				get_color(iter, fractol->intesite));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
