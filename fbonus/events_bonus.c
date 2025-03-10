/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:51:24 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/10 17:37:53 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	if (keycode == 123)
		fractol->move_x -= 0.05 * fractol->zoom;
	if (keycode == 124)
		fractol->move_x += 0.05 * fractol->zoom;
	if (keycode == 126)
		fractol->move_y -= 0.05 * fractol->zoom;
	if (keycode == 125)
		fractol->move_y += 0.05 * fractol->zoom;
	if (keycode == 69)
		fractol->intesite += 10;
	if (keycode == 78)
		fractol->intesite -= 10;
	if (fractol->type == 0)
		draw_mandelbrot(fractol);
	else if (fractol->type == 2)
		draw_ship(fractol);
	else
		draw_julia(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double (mouse_cr), (mouse_ci), (zoom_factor);
	if (fractol->type == 1)
		y = HEIGHT - y - 1;
	mouse_cr = (x - WIDTH / 2.0) * (4.0 / WIDTH) 
		* fractol->zoom + fractol->move_x;
	mouse_ci = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) 
		* fractol->zoom + fractol->move_y;
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5) 
		zoom_factor = 1 / 1.1;
	else
		return (0);
	fractol->move_x = mouse_cr + (fractol->move_x - mouse_cr) * zoom_factor;
	fractol->move_y = mouse_ci + (fractol->move_y - mouse_ci) * zoom_factor;
	fractol->zoom *= zoom_factor;
	if (fractol->type == 0)
		draw_mandelbrot(fractol);
	else if (fractol->type == 2)
		draw_ship(fractol);
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
