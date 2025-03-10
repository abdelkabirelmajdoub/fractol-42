/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:51:24 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/04 16:30:38 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	notify_exit(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_image(fractol->mlx, fractol->img);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		notify_exit(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom *= 1.1;
	else if (button == 5)
		fractol->zoom /= 1.1;
	if (fractol->type == 0)
		draw_mandelbrot(fractol);
	else
		draw_julia(fractol);
	return (0);
}

void	events_exit(t_fractol *fractol)
{
	mlx_hook(fractol->win, 17, 0, notify_exit, fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
}
