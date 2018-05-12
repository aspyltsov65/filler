/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:59:25 by apyltsov          #+#    #+#             */
/*   Updated: 2018/04/17 14:59:32 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_valid_token(t_fil *fl)
{
	int	i;
	int	j;
	int	n;

	fl->count = 0;
	i = -1;
	while (++i < fl->ty)
	{
		j = -1;
		while (++j < fl->tx)
		{
			if (fl->token[i][j] == '*')
				fl->count++;
		}
	}
	fl->c_x = (int *)ft_memalloc(sizeof(int) * fl->count);
	fl->c_y = (int *)ft_memalloc(sizeof(int) * fl->count);
	n = 0;
	i = -1;
	while (++i < fl->ty)
	{
		j = -1;
		while (++j < fl->tx)
			if (fl->token[i][j] == '*')
			{
				fl->c_y[n] = i;
				fl->c_x[n] = j;
				n++;
			}
	}
}

void	ft_map_token(t_list **list, char **arr)
{
	int		y;
	t_list	*cur;

	y = 0;
	while ((*list))
	{
		arr[y] = ft_strdup((*list)->content);
		cur = *list;
		(*list) = (*list)->next;
		free(cur->content);
		free(cur);
		y++;
	}
}

void	ft_read_map_token(int val, t_fil *fl, t_list *list, t_list *begin)
{
	int		m;
	char	*line;

	m = -1;
	while (++m < val && get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]))
			ft_createlist(&list, &line[4]);
		if (line[0] == '.' || line[0] == '*')
			ft_createlist(&begin, line);	
		free(line);
	}
	if (val == fl->my)
	{
		fl->my -= 1;
		fl->map = (char **)ft_memalloc(sizeof(char *) * fl->my);
		ft_map_token(&list, fl->map);
	}
	else
	{
		fl->token = (char **)ft_memalloc(sizeof(char *) * fl->ty);
		ft_map_token(&begin, fl->token);
		ft_valid_token(fl);
		ft_algoritm(fl);
	}
}

void	ft_read(t_fil *fl)
{
	char	*line;
	t_list	*list;
	t_list	*begin;

	list = NULL;
	begin = NULL;
	while (get_next_line(0, &line) > 0 )
	{
		if (ft_strstr(line, "Plateau") != NULL)
		{
			fl->my = ft_atoi(&line[8]) + 1;
			fl->mx = ft_atoi(&line[10]);
			ft_read_map_token(fl->my, fl, list, begin);
		}
		if (ft_strstr(line, "Piece") != NULL)
		{
			fl->ty = ft_atoi(&line[6]);
			fl->tx = ft_atoi(&line[8]);
			ft_read_map_token(fl->ty, fl, list, begin);
		}
		free(line);
	}
}

int main()
{
	t_fil	*fl;
	char	*line;

	if(!(fl = (t_fil *)malloc(sizeof(*fl))))
		perror("Error");
	fl->mx = 0;
	fl->my = 0;
	fl->tx = 0;
	fl->ty = 0;
	get_next_line(0, &line);
	if (!(ft_strstr(line, "p1")))
		fl->symb = 'X';
	else
		fl->symb = 'O';
	ft_read(fl);
	return (0);
}
