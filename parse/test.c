/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:43:48 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/03 18:43:52 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"
#include "include/libft.h"
# include "stdio.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
	int r;
	char *line;
	int fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0); //ERREUR DE LECTURE
	while ((r = get_next_line(fd,&line)) > 0)
		printf("%s\t%d", line, r);
}
