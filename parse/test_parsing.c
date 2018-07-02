/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:43:48 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/05 21:32:15 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stdio.h"
#include "include/rtv1.h"


int main(int argc, char **argv)
{
	t_info info;

	if (argc == 2)
	{
		if (parsing(&info, argv[1]) == 1)
			printf("ok");
	}
	else
		return (0); //USAGE
}
