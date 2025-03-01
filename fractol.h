/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:15:18 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/01 12:08:49 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>// remove them after that
# include <stdlib.h>// 
# include <unistd.h>// 
# include <string.h>//
# include "minilibx/mlx.h"

# define HEIGHT	800
# define WIDTH	800


typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	double	julia_cr;
    double  julia_ci;
	double	zoom;
	double	move_x;
	double	move_y;
}	t_fractol;

void	events_exit(t_fractol *fractol);
int		notify_exit(t_fractol *fractol);
void	error(void);
int		mandelbrot(double cr, double ci);
void	put_pixel(t_fractol *fractol, int x, int y, int color);
void	setup_hooks(t_fractol *fractol);
int		get_color(int iter, int max_iter);
int		julia(double zr, double zi, double cr, double ci);
void	draw_julia(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);
// int		mouse_hook(int button, int x, int y, t_fractol *fractol);
int		ft_strcmp(const char *s1, const char *s2);
double	ft_atod(const char *s);
#endif