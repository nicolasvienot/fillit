/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:58:32 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/10 17:55:03 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_testerror1(char *str)
{
	int		i;
	int		bn;

	i = 0;
	bn = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '\n')
			bn++;
		if ((str[i] == '\n' && (str[i + 1] == '\n'
			|| str[i + 1] == '\0')) || str[i + 1] == '\0')
		{
			if (bn != 4)
				return (0);
			if (str[i + 1] == '\n' && (str[i + 2] != '.' && str[i + 2] != '#'))
				return (0);
			bn = 0;
			i++;
		}
		i++;
	}
	return (1);
}

static int		ft_testerror2(char *str)
{
	int		i;
	int		dot;
	int		hash;

	i = 0;
	dot = 0;
	hash = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		if (str[i] == '#')
			hash++;
		if ((str[i] == '\n' && (str[i + 1] == '\n'
			|| str[i + 1] == '\0')) || str[i + 1] == '\0')
		{
			if (dot != 12 || hash != 4)
				return (0);
			dot = 0;
			hash = 0;
			i++;
		}
		i++;
	}
	return (1);
}

static int		ft_testerror3(char *str)
{
	int		i;
	int		j;
	int		link;

	i = 0;
	j = 1;
	link = 0;
	while (str[i])
	{
		while (str[i])
		{
			if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
				break ;
			if (str[i] == '#')
				link += ft_checklinks(str, i, j);
			j++;
			i++;
		}
		if (link != 6 && link != 8)
			return (0);
		link = 0;
		j = 1;
		i = i + 2;
	}
	return (1);
}

int				ft_checklinks(char *str, int i, int j)
{
	int link;

	link = 0;
	if (j > 5 && str[i - 5] == '#')
		link++;
	if (j > 1 && str[i - 1] == '#')
		link++;
	if (j < 19 && str[i + 1] == '#')
		link++;
	if (j < 15 && str[i + 5] == '#')
		link++;
	return (link);
}

int				ft_testerror(char *str)
{
	if (!ft_testerror1(str))
		return (0);
	if (!ft_testerror2(str))
		return (0);
	if (!ft_testerror3(str))
		return (0);
	return (1);
}
