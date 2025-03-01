/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:51:51 by ael-majd          #+#    #+#             */
/*   Updated: 2025/03/01 12:08:28 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_color(int iter, int max_iter)
{
    if (iter == max_iter)
        return (0x000000);
    
    int red = (iter * 5) % 256;
    int green = (iter * 7) % 256;
    int blue = (iter * 11) % 256;
    return ((red << 16) | (green << 8) | blue);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	after_virgul(const char *s, double *r, int *i)
{
	double	f;

	f = 0.1;
	if (s[(*i)++] == '.')
	{
		while ((s[*i] >= '0' && s[*i] <= '9') && s[*i])
		{
			*r += (s[*i] - '0') * f;
			f *= 0.1;
			(*i)++;
		}
	}
}

double	ft_atod(const char *s)
{
	double	r;
	int i;
	int sign;

	r = 0;
	i = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)) 
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && s[i])
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	after_virgul(s, &r, &i);
	return (r * sign);
}

void error(void)
{
	write(2, "Usage: ./fractol mandelbrot OR ./fractol julia <cr> <ci>\n", 57);
	exit(1);
}