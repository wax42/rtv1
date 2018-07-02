/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:15:07 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/06 15:15:08 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXLIB_H
# define MLXLIB_H

typedef	int		t_color __attribute__((vector_size(3 * sizeof(int))));

# include "rtv1.h"

unsigned int		*ft_get_data_addr(void *ptr);
int					hsv_rgb(float h, float s, float v);
int					cr_col(float a, float b, float c);

#endif