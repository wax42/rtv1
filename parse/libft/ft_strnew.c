/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:51:53 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/02 01:58:42 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)ft_memalloc(size + 1);
	return (str);
}
