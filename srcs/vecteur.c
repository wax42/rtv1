/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:06:28 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/01 17:06:29 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect		vctr_add(const t_vect a, const t_vect b)
{
	return (a + b);
}

t_vect		vctr_sous(const t_vect a, const t_vect b)
{
	return (a - b);
}

t_vect		vctr_mul(const t_vect a, const float b)
{
	t_vect	tmp;

	tmp[0] = a[0] * b;
	tmp[1] = a[1] * b;
	tmp[2] = a[2] * b;
	return (tmp);
}

t_vect		vctr_div(const t_vect a, const float b)
{
	t_vect	tmp;

	if (b == 0)
		return (tmp = (t_vect){0});
	tmp[0] = a[0] / b;
	tmp[1] = a[1] / b;
	tmp[2] = a[2] / b;
	return (tmp);
}

float		produit_scalaire(const t_vect a, const t_vect b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}
