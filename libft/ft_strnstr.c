/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:13:10 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 15:09:00 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t p;

	i = 0;
	p = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		p = 0;
		if (needle[p++] == haystack[i])
		{
			i++;
			while (needle[p] != '\0' && needle[p] == haystack[i] && i < len)
			{
				i++;
				p++;
			}
			if (needle[p] == '\0')
				return ((char *)&haystack[i - p]);
		}
		i++;
	}
	return (NULL);
}
