/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:29:51 by hcasanov          #+#    #+#             */
/*   Updated: 2019/01/10 17:17:12 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_counthashtag(char *str)
{
	int		i;
	int		hash;

	i = 0;
	hash = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		i++;
	}
	return (hash / 4);
}

int			ft_nbpieces(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		ft_nb_zero(int *j, int *k, int *l)
{
	*j = 0;
	*k = 0;
	*l = 0;
}

void		ft_usage(void)
{
	ft_putstr("usage: ./fillit file\n");
	exit(EXIT_FAILURE);
}

void		ft_exiterror(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}
