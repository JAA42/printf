/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:04:34 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 14:54:06 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*str1cur;
	unsigned char	*str2cur;
	size_t			i;

	if (n == 0)
		return (str1);
	str1cur = (unsigned char*)str1;
	str2cur = (unsigned char*)str2;
	i = 0;
	while (i < n)
	{
		*str1cur = *str2cur;
		str1cur++;
		str2cur++;
		i++;
	}
	return (str1);
}
