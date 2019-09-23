/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:53:07 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 16:18:15 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		nbrcar(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

static int		nbrmot(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
		{
			if (str[i - 1] != '\t' && str[i - 1] != '\n' && str[i - 1] != ' ')
				count++;
		}
		if (!str[i + 1] && (str[i] != '\n' && str[i] != '\t' && str[i] != ' '))
			count++;
		i++;
	}
	return (count);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((tab = malloc(sizeof(char*) * (nbrmot(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			i++;
		if (str[i])
		{
			k = 0;
			if ((tab[j] = malloc(sizeof(char) * (nbrcar(str, i) + 1))) == NULL)
				return (NULL);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
