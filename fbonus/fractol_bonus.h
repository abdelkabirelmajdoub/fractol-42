/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:15:18 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/10 15:30:30 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include <stdlib.h>
# include <unistd.h> 
# include <math.h>
# include "../minilibx/mlx.h"

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
	int		intesite;
	double	julia_cr;
	double	julia_ci;
	double	zoom;
	double	move_x;
	double	move_y;
}	t_fractol;

void	events_exit(t_fractol *fractol);
int		notify_exit(t_fractol *fractol);
void	error(void);
int		mandelbrot(double cr, double ci, t_fractol *fractol);
void	put_pixel(t_fractol *fractol, int x, int y, int color);
int		get_color(int iter, int max_iter);
int		julia(double zr, double zi, t_fractol *fractol);
void	draw_julia(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);
void	draw_ship(t_fractol *fractol);
int		ship(double cr, double ci, t_fractol *fractol);
int		ft_strcmp(const char *s1, const char *s2);
double	ft_atod(const char *s);
#endif