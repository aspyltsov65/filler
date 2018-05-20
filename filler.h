/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:48:48 by apyltsov          #+#    #+#             */
/*   Updated: 2018/04/17 14:48:51 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <ncurses.h>

typedef struct	s_fil
{
	char		**map;
	char		**token;
	char		symb;
	int			tx;
	int			ty;
	int			*c_y;
	int			*c_x;
	int			count;
	int			mx;
	int			my;
	int			cord[2];
}				t_fil;

typedef struct	s_bon
{
	int			mx;
	int			my;
	char		**map;
	int			name;
}				t_bon;

void			ft_read(t_fil *fl);
void			ft_parse_list(t_list **list, char **arr);
int				ft_check(t_fil *fl, int i, int j);
void			ft_valid_token(t_fil *fl);
void			ft_algoritm(t_fil *fl);
void			ft_read_map_token(int val, t_fil *fl, t_list *list, t_list *b);
void			ft_algor(int i, int j, t_fil *fl, int l);
void			ft_result(t_fil *fl, int count);
void			ft_vizualize(t_bon *fl);
void			ft_read_for_bonus(t_list *list, t_bon *fl);
void			ft_reading(t_bon *fl, t_list *list, char *line);
void			ft_color(t_bon *fl, int i, int j, WINDOW *playwin);

#endif
