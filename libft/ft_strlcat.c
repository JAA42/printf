/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:10:54 by avallois          #+#    #+#             */
/*   Updated: 2017/11/24 17:57:31 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t n1;
	size_t n2;

	i = 0;
	n1 = ft_strlen(dest);
	n2 = ft_strlen(src);
	if (size <= n1)
		return (n2 + size);
	while (i < size - n1 - 1 && src[i])
	{
		dest[n1 + i] = src[i];
		i++;
	}
	dest[n1 + i] = '\0';
	return (n1 + n2);
}
