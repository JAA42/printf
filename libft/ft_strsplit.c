/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:26:55 by avallois          #+#    #+#             */
/*   Updated: 2018/02/14 20:14:34 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fillstr(const char *str1, char *str2, int start, int end)
{
	int i;

	i = 0;
	while (start < end)
		str2[i++] = str1[start++];
	str2[i] = '\0';
}

static void		ft_filltab(const char *s, char **tab, char c)
{
	int i;
	int l;
	int p;

	l = 0;
	p = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		l = i;
		if (s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[p] = (char*)malloc(sizeof(char) * (i - l + 1));
			ft_fillstr(s, tab[p], l, i);
			p++;
		}
	}
	tab[p] = NULL;
}

static int		ft_countchars(const char *s, char c)
{
	int i;
	int ct;

	i = 0;
	ct = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			ct++;
		}
	}
	return (ct);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		ct;

	tab = NULL;
	if (s != NULL)
	{
		ct = ft_countchars(s, c);
		tab = (char**)malloc(sizeof(char*) * (ct + 1));
		if (tab != NULL)
			ft_filltab(s, tab, c);
	}
	return (tab);
}
