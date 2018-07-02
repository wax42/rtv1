/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:16:40 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/04 22:33:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/rtv1.h"

/*
**	code 0 malloc
**	code 1 parsing
*/

void ft_exit(const int8_t code, const char *error, const char *line)
{
	if (code == 0)
	{
		ft_putendl("Error Malloc");
		ft_putendl(error);
	}
	else if (code == 1)
	{
		ft_putstr("Errror parsing:\t");
		ft_putendl(error);
		ft_putstr("Line:\t");
		ft_putendl(line);
	}
	exit(0);
}
