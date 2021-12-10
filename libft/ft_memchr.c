/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:00:41 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/24 10:27:34 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	c = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == c)
			return ((void *)str);
		str++;
	}
	return (0);
}
