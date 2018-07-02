/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:59:07 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/01 17:59:10 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	vctr_norm(t_vect a)
{
	return (sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]));
}

t_vect	vctr_normaliser(t_vect a)
{
	return (vctr_div(a, vctr_norm(a)));
}

t_vect	cr_vctr(float x, float y, float z)
{
	t_vect	a;

	a[0] = x;
	a[1] = y;
	a[2] = z;
	return (a);
}