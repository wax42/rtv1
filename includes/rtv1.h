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

#ifndef RTV1_H
# define RTV1_H

# define WIN_H 480
# define WIN_W 640
# define DISTV 1.0
# define LONGV 0.35
# define LARGV 0.5

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X.h>
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# include "libft.h"
# include "libmaths.h"


// # include "rtv1.h"

/*
**  l_obj
**	0 : SPHERE
**  1 : PLAN
**	2 : CONE
**  3 : CYLINDRE
*/


typedef struct	s_obj
{
	int				type;
	void			*obj;
	int				*dist;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_cam
{
	t_point		pos;
	t_point		p_look;
	t_vect		haut;
	t_vect		direct;
	t_vect		vect_droite;
	t_vect		difHGC;
}				t_cam;

typedef struct	s_info
{
	void			*mlx_t;
	void			*window;
	int				(*itr_obj[4])(t_vect ray, void *obj, int *tmp);
	void			*p_img;
	unsigned int	*img;
	t_obj			*obj;
	t_cam			cam;	
}				t_info;

int		itr_sphere(t_vect ray, void *obj, int *tmp);
int		itr_cone(t_vect ray, void *obj, int *tmp);
int		itr_plan(t_vect ray, void *obj, int *tmp);
int		itr_cylindre(t_vect ray, void *obj, int *tmp);

int		prepare_algo(t_info info);
int		raytracing(t_info info, t_vect ray, int x, int y);
void	printvct(t_vect v);
int 	ft_key(int k, void *info);


#endif
