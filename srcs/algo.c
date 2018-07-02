/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:54:14 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/06 13:54:17 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
/*
**return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
*/
int		map_i(int i)
{
	return ((i - 10) * (100 - 0) / (100000 - 10) + 0);
}

int		itr_sphere(t_vect ray, t_sphere sphere, t_vect l, int intensite)
{
	float	a;
	float	b;
	float	c;
	t_vect	sphr;
	t_vect	dlt;
	t_vect	p;
	t_vect	n;

	sphr = cr_vctr(sphere[0], sphere[1], sphere[2]);
	a = 1.0;
	b = 2.0 * produit_scalaire(vctr_normaliser(ray), vctr_sous(ray, sphr));
	c = vctr_norm(vctr_sous(ray, sphr)) - sphere[3] * sphere[3];
	dlt = delta(a, b, c);
	if (dlt[0] < 0)
		return (0);
	if (dlt[2] < 0)
		return (0);
	p = vctr_add(ray, vctr_mul(vctr_normaliser(ray), 
		dlt[(dlt[1] > 0) ? 1 : 2]));
	n = vctr_normaliser(vctr_sous(p, sphr));
	return (fabs((produit_scalaire(vctr_normaliser(vctr_sous(l, p)), n) 
		* intensite) / vctr_norm(vctr_sous(l, p))));
}

int		raytracing(t_info info)
{
	t_vect	vue;
	int		h;
	int		i;
	int		v;
	t_sphere sphere;
	t_vect	l;
	int		min;
	int		max;

	max = 36000;
	min = 0;
	sphere[0] = -300;
	sphere[1] = -300;
	sphere[2] = -140.0;
	sphere[3] = 300.0;
	l = cr_vctr(-5000,-5000,-5000);
	h = 0;
	v = 0;
	while (h < info.resolution[0])
	{
		while (v < info.resolution[1])
		{
			vue = cr_vctr(v - info.resolution[1] / 2.0,
				h - info.resolution[1] / 2.0, 
				(info.resolution[0] / (2.0 * tan(2.0 / 3.0 * M_PI))));
			i = itr_sphere(vue, sphere, l, 1000000000);

			if (i == 0)
				info.img[v + h * info.resolution[0]] = 0;
			else
			{
				printf("%d\n", i);
				i = map_i(i);
				info.img[v + h * info.resolution[0]] = 36 * 1000000 + 50 * 1000 + i;
			}
			v++;
		}
		v = 0;
		h++;
	}
	return (1);
}