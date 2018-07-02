/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:45:24 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/02 01:54:49 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*str;

	if ((str = (char *)ft_memalloc(n + 1)) == NULL)
		return (NULL);
	return (ft_strncpy(str, s1, n));
}
