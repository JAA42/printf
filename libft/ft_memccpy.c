/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:05:14 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 14:51:26 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1cur;
	unsigned char	*str2cur;

	str1cur = (unsigned char *)str1;
	str2cur = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		str1cur[i] = str2cur[i];
		if (str2cur[i] == (unsigned char)c)
			return (str1cur + i + 1);
		i++;
	}
	return (NULL);
}
