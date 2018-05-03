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
	// int	max_x;
	// int	max_y;

	j = -1;
	while (++j < fl->tx)
	{
		i = -1;
		while (++i < fl->ty)
			if (fl->token[i][j] == '*')
			{
				fl->ti = i;
				fl->tj = j;
				break ;
			}
		if (i != fl->ty)
			break ;
	}
	// max_x = 0;
	// max_y = 0;
	// fl->min_y = fl->ty;
	// i = -1;
	// while (++i < fl->ty)
	// {
	// 	j = -1;
	// 	while (++j < fl->tx)
	// 		if (fl->token[i][j] == '*')
	// 		{
	// 			if (i < fl->min_y)
	// 				fl->min_y = i;
	// 			if (i > max_y)
	// 				max_y = i;
	// 			if (j > max_x)
	// 				max_x = j;
	// 		}
	// }
	dprintf(2, "before token fl->ty %d fl->tx %d\n", fl->ty, fl->tx);
	dprintf(2, "fl->ti %d fl->tj %d\n", fl->ti, fl->tj);
	dprintf(2, "token fl->ty %d fl->tx %d\n", fl->ty, fl->tx);
}

void	ft_createlist(t_lst **list, char *content)
{
	t_lst	*time;
	t_lst	*elem;

	time = *list;
	elem = (t_lst *)ft_memalloc(sizeof(t_lst));
	elem->cont = ft_strdup(content);
	elem->next = NULL;
	if (time == NULL)
		*list = elem;
	else
	{
		while (time->next)
			time = time->next;
		time->next = elem;
	}
}

void	ft_map_token(t_lst **list, t_fil *fl, char **arr, int flag)
{
	int		y;
	t_lst	*cur;

	y = 0;
	if (flag)
		fl->mx = ft_strlen((*list)->cont);
	else
		fl->tx = ft_strlen((*list)->cont);
	while ((*list))
	{
		arr[y] = ft_strdup((*list)->cont);
		cur = *list;
		(*list) = (*list)->next;
		free(cur->cont);
		free(cur);
		y++;
	}
}

void	ft_read(t_fil *fl)
{
	char	*line;
	int		i;
	t_lst	*list;
	t_lst	*begin;

	i = 0;
	list = NULL;
	begin = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]) && ++fl->my)
			ft_createlist(&list, &line[4]);
		if ((line[0] == '*' || line[0] == '.') && ++fl->ty)
			ft_createlist(&begin, line);
		free(line);
	}
	fl->map = (char **)ft_memalloc(sizeof(char *) * fl->my);
	ft_map_token(&list, fl, fl->map, 1);
	fl->token = (char **)ft_memalloc(sizeof(char *) * fl->ty);
	ft_map_token(&begin, fl, fl->token, 0);
	ft_valid_token(fl);
	ft_algoritm(fl);
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
	fl->ti = 0;
	fl->tj = 0;
	get_next_line(0, &line);
	if (!(ft_strstr(line, "p1")))
		fl->symb = 'X';
	else
		fl->symb = 'O';
	ft_read(fl);
	return (0);
}
