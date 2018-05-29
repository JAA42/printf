/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:25:12 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 15:22:08 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (s != NULL)
	{
		str = (char *)malloc(sizeof(*str) * (len + 1));
		i = 0;
		if (str != NULL)
		{
			while (i != len)
				str[i++] = s[start++];
			str[i] = '\0';
		}
	}
	return (str);
}
