/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:01:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/02 01:25:42 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] && n > i)
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}
