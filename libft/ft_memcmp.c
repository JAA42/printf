/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:07:15 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 14:53:26 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1cur;
	unsigned char	*str2cur;
	size_t			i;

	i = 0;
	str1cur = (unsigned char*)s1;
	str2cur = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*str1cur == *str2cur && i != n - 1)
	{
		str1cur++;
		str2cur++;
		i++;
	}
	return (*str1cur - *str2cur);
}
