/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:34:44 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/03 18:52:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 255
# define MAX_C 1000
# include <stdlib.h>

int					get_next_line(const int fd, char **line);

#endif
