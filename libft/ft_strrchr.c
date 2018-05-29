/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:12:05 by avallois          #+#    #+#             */
/*   Updated: 2017/11/23 15:10:04 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != str[0])
	{
		if ((int)str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	if ((int)str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}
