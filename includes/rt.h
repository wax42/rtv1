/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:09:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/12/27 16:10:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include "rt_ts.h"
# define WIN_W 980
# define WIN_H 720

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*render;
	char			*img;
	t_rtv1			core;
	unsigned char	aa;
	char			on;
}				t_env;

int				init_env(t_env *e);
void			ft_raytracer(t_env *e);
void			projection(t_env *e);
#endif
