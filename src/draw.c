/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:19:40 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/01 12:33:38 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	offset;

	offset = (y * fractol->line_len) + (x * (fractol->bpp / 8));
	*(unsigned int *)(fractol->addr + offset) = color;
}

int	mandelbrot(double cr, double ci)
{
	double (zr), (zi), (tmp);
	int (iter), (max_iter);
	zr = 0;
	zi = 0;
	iter = 0;
	max_iter = 100;
	while (zr * zr + zi * zi <= 4 && iter < max_iter)
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
			cr = (x - WIDTH / 2.0) * (4.0 / WIDTH) * fractol->zoom;
			ci = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) * fractol->zoom;
			iter = mandelbrot(cr, ci);
			put_pixel(fractol, x, y, get_color(iter, 100));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

int	julia(double zr, double zi, double cr, double ci)
{
	double	tmp;
	int		iter;
	int		max_iter;

	iter = 0;
	max_iter = 100;
	while (zr * zr + zi * zi <= 4 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
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
			zr = (x - WIDTH / 2.0) * (4.0 / WIDTH) * fractol->zoom;
			zi = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) * fractol->zoom;
			iter = julia(zr, zi, fractol->julia_cr, fractol->julia_ci);
			put_pixel(fractol, x, HEIGHT - y - 1, get_color(iter, 100));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
