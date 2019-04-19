/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:00:17 by vguerand          #+#    #+#             */
/*   Updated: 2018/12/31 11:00:51 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "rtv1.h"

#include "stdio.h"

int		ft_key(int k, void *info)
{
	(void)info;
	if (k == 53)
		exit(0);
	return (0);
}

static void	check_arg(int argc, char **argv)
{
	if (argc != 2 || ft_strcmp(argv[1] + ft_strlen(argv[1]) - 5, ".json") != 0)
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" <file.json>\n", 2);
		exit(EXIT_FAILURE);
	}

}


t_obj	*init_rv1_obj()
{
	t_obj *obj;
	t_vect vect;


	if (!(obj = (t_obj*)malloc(sizeof(t_obj))))
		return NULL;
	vect = m_vec2_create(0.0, 0.0);
	// obj->obj
	printf("%f", vect[0]);
	obj->type = 1; //plan
	return obj;
}

// t_scene				*json_to_rtv1(char **files)
// {
// 	t_obj			*json;
// 	t_scene			*scene;

// 	json = json_parser(*files); // penser a faire la loop qui fait malloc les scenes
// 	return (scene);
// }

int			main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
//	json_to_rtv1(all_json);
	info.obj = init_rv1_obj();


	if (!(info.mlx_t = mlx_init()))
		return (0);
	info.window = mlx_new_window(info.mlx_t, WIN_W, WIN_H, "rtv1");

	mlx_key_hook(info.window, ft_key, &info);
	mlx_loop(info.mlx_t);
	// ft_raytracer(&e);
	return (0);
}
