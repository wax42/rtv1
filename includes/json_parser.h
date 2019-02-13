/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:43:59 by vguerand          #+#    #+#             */
/*   Updated: 2019/01/05 23:44:40 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_PARSER_H
# define JSON_PARSER_H

# include "json_parser_errors.h"
# include "libft.h"
# include "libftvguerand.h"
# include <fcntl.h>
# include <stdio.h>
typedef int bool;
# define true 1
# define false 0
# define DEBUG_PRINT 0
# define PRINT_TREE 0

typedef enum		s_type
{
	NOTYPE,
	INTEGER,
	STRING,
	FLOAT,
	BOOL,
	OBJECT,
	NULL_ELEM,
	ARRAY,
}					e_type;

typedef union		s_value
{
	int				t_int;
	float			t_float;
	bool			t_bool;
	char			*t_string;
	void			*t_array;
	void			*t_object;
	int				t_null;
}					u_value;

typedef struct		s_elem
{
	char			*key;
	e_type			type;
	u_value			value;
	struct s_elem	*next;
}					t_obj;




/*
**	TO DELETE
*/
void		show_elem(t_obj *elem);
void		show_one_elem(t_obj *elem, int padding);
void		show_every_elem(t_obj *elem, int padding);

/*
** JSON PARSER
*/
t_obj				*json_parser(char *file);
/*
** Utils
*/
int			update_line(int fd, char **line);
void		error_free_line(char *line, char *error);
int			json_pass_whitespaces(char **line, int *i, int fd);
char		end_of_value(char c);
void		json_error(char *error);

/*
** Elem structures
*/
t_obj		*create_elem();
u_value		set_value_of_type(e_type type, void *defaulty);
t_obj		*create_init_obj(char *key, e_type type, void *value);
/*
**	Recognize elements
*/
t_obj		*json_obj_recursive(int fd, char **line, int *i);
t_obj		*json_array_recursive(int fd, char **line, int *i);
int			recognize_type(t_obj *current, char **line, int *i);
int			recognize_key(int *i, t_obj *current, char *line, int fd);
int			json_recognize_number(t_obj *current, char *line, int *i);
int			json_recognize_string(t_obj *current, char *line, int *i);
int			json_recognize_bool(t_obj *current, char *line, int *i);
int			json_recognize_null(t_obj *current, char *line, int *i);
int			json_recognize_array(t_obj *current, char **line, int *i, int fd);
int			json_recognize_object(t_obj *current, char **line, int *i, int fd);

/*
**	SINGLETONS
*/
int			get_obj_logs_line();
void		set_line_number(int nbr);
void		update_logs_line(int nbr);
/*
** Generic functions
*/

void				*json_malloc(size_t size);
void				ft_error(char *str);
#endif
