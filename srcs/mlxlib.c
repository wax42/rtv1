/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:02:38 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/06 15:02:40 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

unsigned int		*ft_get_data_addr(void *ptr)
{
	int		bpp;
	int		s_l;
	int		endian;

	return ((unsigned int*)mlx_get_data_addr(ptr, &(bpp), &(s_l), &(endian)));
}

int	cr_col(float a, float b, float c)
{
	t_color	cc;

	cc[0] = (int)(a * 255);
	cc[1] = (int)(b * 255);
	cc[2] = (int)(c * 255);
	printf("%d\n", cc[0] * 1000000 + cc[1] * 1000 + cc[2]);
	return (cc[0] * 1000000 + cc[1] * 1000 + cc[2]);
}

int	hsv_rgb(float h, float s, float v)
{
	int	i;
	float	f;
	float	p;
	float	q;
	float	t;

	h /= 60;
	i = floor(h);
	f = h - i;
	p = v * (1.0 - s);
	q = v * (1.0 - s * f);
	t = v * (1.0 - s * (1.0 - f));
	if (i == 0)
		return (cr_col(v,t,p));
	else if (i == 1)
		return (cr_col(q,v,p));
	else if (i == 2)
		return (cr_col(p,v,t));
	else if (i == 3)
		return (cr_col(p,q,v));
	else if (i == 4)
		return (cr_col(t,p,v));
	else
		return (cr_col(v,p,q));
}