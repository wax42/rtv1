/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:00:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/03 18:52:35 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/libft.h"

static void	fuck_the_norm(char **line, char *tmp)
{
	ft_strdel(line);
	*line = tmp;
}

static int	gnl_copy_buffer(char *buffer, int *buff_position, char **line,
	int *flag)
{
	char	*search;

	if (*buff_position == -1)
		return (0);
	search = ft_strchr(buffer + *buff_position, '\n');
	if (search == NULL)
	{
		*line = ft_strdup(buffer + *buff_position);
		if (*line == NULL)
			return (-1);
		*buff_position = -1;
		*flag = 1;
		return (0);
	}
	else
	{
		*line = ft_strndup(buffer + *buff_position,
			search - buffer - *buff_position);
		if (*line == NULL)
			return (-1);
		*buff_position = (search - buffer) + 1;
		return (1);
	}
}

static int	gnl_copy_fd(const int fd, char *buffer, int *buff_position,
	char **line)
{
	char	*search;
	char	*tmp;
	int		read_len;

	while ((read_len = read(fd, buffer, BUFF_SIZE)))
	{
		if (buffer[0] == '\0')
			return (0);
		buffer[read_len] = 0;
		if ((search = ft_strchr(buffer, '\n')) == NULL)
		{
			if (!(tmp = ft_strjoin(*line, buffer)) || ft_strlen(*line) > MAX_C)
				return (-1);
			fuck_the_norm(line, tmp);
		}
		else
		{
			*buff_position = (search - buffer) + 1;
			if ((tmp = ft_strnjoin(*line, buffer, search - buffer)) == NULL)
				return (-1);
			fuck_the_norm(line, tmp);
			return (1);
		}
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1];
	static int	buff_position;
	int			flag;
	int			ret;

	flag = 0;
	if (BUFF_SIZE < 0 || fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if ((ret = gnl_copy_buffer(buffer, &buff_position, line, &flag)) == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	if ((ret = gnl_copy_fd(fd, buffer, &buff_position, line)) == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	if (ft_strlen(*line) > 0 && flag)
		return (1);
	return (0);
}
