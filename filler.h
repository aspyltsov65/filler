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

typedef struct	s_fil
{
	char		**map;
	char		**token;
	char		symb;
	int			tx;
	int			ty;
	int			mx;
	int			my;

}				t_fil;

typedef struct		s_lst
{
	char			*cont;
	struct s_lst	*next;
}					t_lst;

void			ft_createlist(t_lst **list, char *content);
void			ft_read(char *name, t_fil *fl);
void			ft_map(t_lst **list, t_fil *fl);
void			ft_token(t_lst **begin, t_fil *fl);

#endif