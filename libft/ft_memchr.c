/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:06:31 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 14:52:33 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*strcur;
	size_t			i;

	strcur = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (*strcur == (unsigned char)c)
			return (strcur);
		strcur++;
		i++;
	}
	return (NULL);
}
