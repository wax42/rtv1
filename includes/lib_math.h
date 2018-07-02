/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:03:20 by smokhtar          #+#    #+#             */
/*   Updated: 2018/05/30 15:03:22 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MATH_H
# define LIB_MATH_H

# include "rtv1.h"

/*
**	t_vect(x;y;z)
**	t_point(x;y;z)
**	t_sphere(x;y;z;r)
**	t_plan(x;y;z;a;b;c)
**	t_cone(x;y;z;r;h)
**	t_cylindre(x;y;z;r;h)
*/



t_vect		vctr_add(const t_vect a, const t_vect b);
t_vect		vctr_sous(const t_vect	a, const t_vect b);
t_vect		vctr_mul(const t_vect a, const float b);
t_vect		vctr_div(const t_vect a, const float b);
float		produit_scalaire(const t_vect a, const t_vect b);

t_vect		vctr_normaliser(t_vect a);
float		vctr_norm(t_vect a);
t_vect		cr_vctr(float x, float y, float z);

t_vect		delta(float a, float b, float c);
#endif
