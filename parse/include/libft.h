/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 01:27:54 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/04 22:35:05 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strdel(char **as);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncpy(char *dst, const char *src, size_t len);

void			*ft_memset(void *b, int c, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);


int				ft_isdigit(int c);
int				ft_atoi(const char *str);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int nb);
void			ft_putendl(char const *s);


#endif
