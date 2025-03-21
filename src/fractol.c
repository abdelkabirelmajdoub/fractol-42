/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:24:26 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/13 13:54:29 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(1);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bpp, 
			&fractol->line_len, &fractol->endian);
	fractol->zoom = 1.0;
}

void	skip_space(char *s, int *i)
{
	while (s[*i] == ' ')
		(*i)++;
}

void	num_err(void)
{
	write(2, "Entre valid number\n", 19);
	exit(1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		fractol.type = 0;
	else if (ac == 4 && !ft_strcmp(av[1], "Julia"))
	{
		if (is_valid(av[2]) == 1 && is_valid(av[3]) == 1)
		{
			fractol.type = 1;
			fractol.julia_cr = ft_atod(av[2]);
			fractol.julia_ci = ft_atod(av[3]);
		}
		else
			num_err();
	}
	else
		error();
	init_fractal(&fractol);
	if (fractol.type == 0)
		draw_mandelbrot(&fractol);
	else
		draw_julia(&fractol);
	events_exit(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
