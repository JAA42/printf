/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:23:57 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 15:05:22 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		n;

	str = NULL;
	n = 0;
	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
		str = (char*)malloc(sizeof(char) * (i + 1));
		if (str != NULL)
		{
			while (n != i)
			{
				str[n] = f(n, s[n]);
				n++;
			}
			str[n] = '\0';
		}
	}
	return (str);
}
