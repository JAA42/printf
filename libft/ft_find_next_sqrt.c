/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_sqrt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:09:34 by avallois          #+#    #+#             */
/*   Updated: 2018/01/04 14:09:38 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i != nb && i * i <= nb)
		i++;
	if (i * i == nb)
		return (i);
	else if (i * i > nb)
		return (ft_find_next_sqrt(nb + 1));
	return (0);
}
