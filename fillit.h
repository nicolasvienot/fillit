/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:05 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/10 19:08:58 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 547
# define BLOC_SIZE 20
# define MAX_BLOC 26
# define BLOC '#'
# define VIDE '.'
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_usage(void);
void		ft_exiterror(void);
int			ft_nbpieces(char **tab);
int			ft_counthashtag(char *str);
int			ft_testerror(char *str);
int			ft_checklinks(char *str, int i, int j);
char		**ft_movetopleft(char **tab);
void		ft_nb_zero(int *j, int *k, int *l);
void		ft_remove_n(char ***tab);
char		***ft_split(char **tab);
char		**ft_solvermagique(char ***tab, int nbpieces);
void		ft_printmap(char **map);
int			ft_mapmini(int nbpieces);
char		**ft_initmap(int size);
void		ft_delete3d(char ***str);
void		ft_deletemap(char **map);

#endif
