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
#include "rt.h"

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


// t_scene				*json_to_rtv1(char **files)
// {
// 	t_obj			*json;
// 	t_scene			*scene;

// 	json = json_parser(*files); // penser a faire la loop qui fait malloc les scenes
// 	return (scene);
// }

int			main(int argc, char **argv)
{
	t_env	e;

	check_arg(argc, argv);
//	json_to_rtv1(all_json);
	// ft_raytracer(&e);
	(void)e;
	return (0);
}
