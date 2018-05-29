/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:15:31 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 15:18:16 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int p;
	int n;

	i = 0;
	p = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		p = 0;
		if (needle[p++] == haystack[i])
		{
			n = i;
			i++;
			while (needle[p] != '\0' && needle[p] == haystack[i++])
				p++;
			if (needle[p] == '\0')
				return ((char *)&haystack[i - p]);
			i = n;
		}
		i++;
	}
	return (NULL);
}
