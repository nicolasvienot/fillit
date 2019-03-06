/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:02:39 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/14 18:31:07 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	bzero_tetriminos(char **tetri, int j)
{
	int		i;

	i = 0;
	while (i < j)
	{
		*tetri = NULL;
		++tetri;
		++i;
	}
}

static char	**ft_read(int fd)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**tab;

	j = 0;
	ft_bzero(buf, BUF_SIZE + 1);
	if ((ret = read(fd, buf, BUF_SIZE)) < 1 || ft_testerror(buf) == 0)
		ft_exiterror();
	i = ft_counthashtag(buf);
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	bzero_tetriminos(tab, i + 1);
	i = 0;
	while (buf[i])
	{
		tab[j] = ft_strsub(buf, j * 21, BLOC_SIZE);
		i += 21;
		j++;
	}
	return (tab);
}

int			main(int ac, char **av)
{
	int		fd;
	char	**tab;
	char	***tab3d;
	char	**map;

	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exiterror();
	tab = ft_read(fd);
	tab = ft_movetopleft(tab);
	tab3d = ft_split(tab);
	map = ft_solvermagique(tab3d, ft_nbpieces(tab));
	ft_printmap(map);
	ft_deletemap(tab);
	ft_delete3d(tab3d);
	ft_deletemap(map);
	return (0);
}
