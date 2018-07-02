/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:01:04 by smokhtar          #+#    #+#             */
/*   Updated: 2018/06/06 14:01:07 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int	main(void)
{
	t_info	info;

	info.resolution[0] = 1024;
	info.resolution[1] = 1024;
	if (/*ac != 2 && parsing(&info, av[1]) == 0 && */!(info.mlx_t = mlx_init()))
		return (0);
	info.window = mlx_new_window(info.mlx_t, info.resolution[0], info.resolution[1], "rtv1");
	info.p_img = mlx_new_image(info.mlx_t, info.resolution[0], info.resolution[1]);
	info.img = ft_get_data_addr(info.p_img);
	if (raytracing(info) == 0)
		return (0);
	mlx_put_image_to_window(info.mlx_t, info.window, info.p_img, 0, 0);
	mlx_key_hook(info.window, ft_key, &info);
	mlx_loop(info.mlx_t);
}

void	printvct(t_vect v)
{
	printf("v(%f ,%f ,%f)\n",v[0],v[1],v[2]);
}
