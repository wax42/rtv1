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

#ifndef LIBMATHS_H
# define LIBMATHS_H
# include <math.h>

/*
**	t_vect(x;y;z)s
**	t_point(x;y;z)
**	t_sphere(x;y;z;r)
**	t_plan(x;y;z;a;b;c)
**	t_cone(x;y;z;r;h)
**	t_cylindre(x;y;z;r;h)
*/

typedef	float	t_vect __attribute__((vector_size(3*sizeof(float))));
typedef	int		t_point __attribute__((vector_size(3*sizeof(int))));
typedef	int		t_sphere __attribute__((vector_size(4*sizeof(float))));

t_vect		m_delta(float a, float b, float c);

t_vect		m_vec_add(const t_vect a, const t_vect b);
t_vect		m_vec_sou(const t_vect a, const t_vect b);

t_vect		m_vec2_create(float x, float y);
t_vect		m_vec2_mul(const t_vect a, const float b);
t_vect		m_vec2_div(const t_vect a, const float b);
float		m_vec2_dot(const t_vect a, const t_vect b);
float		m_vec2_norm(t_vect a);
t_vect		m_vec2_norma(t_vect a);

t_vect		m_vec3_create(float x, float y, float z);
t_vect		m_vec3_mul(const t_vect a, const float b);
t_vect		m_vec3_div(const t_vect a, const float b);
float		m_vec3_dot(const t_vect a, const t_vect b);
float		m_vec3_norm(t_vect a);
t_vect		m_vec3_norma(t_vect a);

#endif
