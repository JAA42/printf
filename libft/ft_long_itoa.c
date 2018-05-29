/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:29:35 by avallois          #+#    #+#             */
/*   Updated: 2018/03/28 17:29:38 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_strrev(char *str)
{
	int		i;
	int		n;
	char	k;

	i = 0;
	n = 0;
	while (str[i] != '\0')
		i++;
	i = i - 1;
	while (n < i)
	{
		k = str[n];
		str[n] = str[i];
		str[i] = k;
		i--;
		n++;
	}
}

static long int		ft_countnbrs(long int n)
{
	long int i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_long_itoa(long int n)
{
	long int	i;
	char		*nbstr;
	long int	p;
	long int	l;
	long int	nb;

	nb = n;
	l = 0;
	i = ft_countnbrs(nb);
	p = (nb >= 0) ? i : (i + 1);
	nb = (nb >= 0) ? nb : -nb;
	nbstr = (char *)malloc(sizeof(*nbstr) * (p + 1));
	if (nbstr == NULL)
		return (nbstr);
	while (l < i)
	{
		nbstr[l++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (i != p)
		nbstr[l++] = '-';
	nbstr[l] = '\0';
	ft_strrev(nbstr);
	return (nbstr);
}
