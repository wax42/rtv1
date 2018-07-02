/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:26:14 by smokhtar          #+#    #+#             */
/*   Updated: 2018/05/30 15:26:15 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define RESOLUTION_X 500
# define RESOLUTION_Y 800
// # include "get_next_line.h"
// # include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X.h>
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# include "mlxlib.h"
# include "libft.h"

typedef	int		t_cam __attribute__((vector_size(6 * sizeof(int))));
typedef	int		t_light __attribute__((vector_size(6 * sizeof(int))));
typedef	float	t_vect __attribute__((vector_size(3 * sizeof(float))));
typedef	int		t_point __attribute__((vector_size(3 * sizeof(int))));
typedef	int		t_sphere __attribute__((vector_size(4 * sizeof(float))));
typedef	int		t_plan __attribute__((vector_size(6 * sizeof(int))));
typedef	int		t_cone __attribute__((vector_size(5 * sizeof(int))));
typedef	int		t_cylindre __attribute__((vector_size(5 * sizeof(int))));

# include "lib_math.h"
// # include "rtv1.h"

/*
**  l_obj
**	0 : SPHERE
**  1 : PLAN
**  2 : LIGHT
**	3 : CONE
**  4 : CYLINDRE
*/

// typedef struct	s_list
// {
// 	t_cam		*cam;
// 	t_sphere	*sphere;
// 	t_plan 		*plan;
// 	t_plan 		*light;
// 	t_cylindre 	*cylindre;
// 	t_cone 		*cone;
// 	int 		l_obj[5];
// }				t_list;

typedef struct	s_info
{
	int				resolution[2];
	void			*mlx_t;
	void			*window;
	void			*p_img;
	unsigned int	*img;
	t_list			*obj;
	t_point 		*lum;
}				t_info;

// void			ft_exit(const int8_t code, const char *error, const char *line);

// int 			parsing(t_info *info, char *str);
int				raytracing(t_info info);
int		itr_sphere(t_vect ray, t_sphere sphere, t_vect l, int intensite);
void	printvct(t_vect v);
int 	ft_key(int k, void *info);

#endif
