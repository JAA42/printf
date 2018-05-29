/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:02:14 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 14:56:38 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	while (i < len)
	{
		*str = (unsigned char)c;
		str++;
		i++;
	}
	return (b);
}
