/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <smokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:26:14 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/04 23:07:42 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H

# define RESOLUTION_X 500
# define RESOLUTION_Y 800
# include "get_next_line.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	int		t_cam __attribute__((vector_size(6 * sizeof(int))));
typedef	int		t_light __attribute__((vector_size(6 * sizeof(int))));
typedef	float	t_vect __attribute__((vector_size(3 * sizeof(float))));
typedef	int		t_point __attribute__((vector_size(3 * sizeof(int))));
typedef	int		t_sphere __attribute__((vector_size(4 * sizeof(int))));
typedef	int		t_plan __attribute__((vector_size(6 * sizeof(int))));
typedef	int		t_cone __attribute__((vector_size(5 * sizeof(int))));
typedef	int		t_cylindre __attribute__((vector_size(5 * sizeof(int))));

// # include "rtv1.h"

/*
**  l_obj
**	0 : SPHERE
**  1 : PLAN
**  2 : LIGHT
**	3 : CONE
**  4 : CYLINDRE
*/

typedef struct	s_list
{
	t_cam		*cam;
	t_sphere	*sphere;
	t_plan 		*plan;
	t_plan 		*light;
	t_cylindre 	*cylindre;
	t_cone 		*cone;
	int 		l_obj[5];
}				t_list;

typedef struct	s_info
{
	int				resolution[2];
	void			*mlx_t;
	void			*window;
	unsigned int	*img;
	t_list			*obj;
	t_point 		*lum;
}				t_info;

void			ft_exit(const int8_t code, const char *error, const char *line);

int 			parsing(t_info *info, char *str);

#endif
