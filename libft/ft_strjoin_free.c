/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:27:04 by avallois          #+#    #+#             */
/*   Updated: 2018/03/28 17:27:07 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int n)
{
	char	*str;
	int		i;

	str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(sizeof(str) * (i + 1));
		if (str != NULL)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
			if (n == 1 || n == 3)
				free((void*)s1);
			if (n == 2 || n == 3)
				free((void*)s2);
		}
	}
	return (str);
}
