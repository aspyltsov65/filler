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
#include <stdio.h>

void	ft_freeshka(void ***dst, size_t i)
{
	while (i != 0)
	{
		free((*dst)[--i]);
		(*dst)[i] = NULL;
	}
	free(*dst);
	*dst = NULL;
}

void	ft_createlist(t_lst **list, char *content)
{
	t_lst	*time;
	t_lst	*elem;

	time = *list;
	elem = (t_lst *)ft_memalloc(sizeof(t_lst));
	elem->cont = content;
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

// void	ft_token(t_lst **begin, t_fil *fl)
// {
// 	int		y;
// 	t_lst	*cur;

// 	if(!(fl->token = (char **)ft_memalloc(sizeof(char *) * fl->ty)))
// 	{
// 		ft_freeshka((void ***)&(fl->token), fl->ty);
// 		perror("Error");
// 	}
// 	fl->tx = ft_strlen((*begin)->cont);
// 	while ((*begin))
// 	{
// 		fl->token[y] = ft_strdup((*begin)->cont);
// 		cur = *begin;
// 		(*begin) = (*begin)->next;
// 		free(cur->cont);
// 		free(cur);
// 		y++;
// 	}
// }

void	ft_map_token(t_lst **list, t_fil *fl, char **arr)
{
	int		y;
	t_lst	*cur;

	y = 0;
	if(!(arr = (char **)ft_memalloc(sizeof(char *) *fl->my)))
	{
		ft_freeshka((void ***)&(fl->map), fl->ty);
		perror("Error");
	}
	if (ft_isdigit((*list)->cont[0]))
		fl->mx = ft_strlen((*list)->cont) - 4;
	else
		fl->tx = ft_strlen((*list)->cont);
	while ((*list))
	{
		if (ft_isdigit((*list)->cont[0]))
			arr[y] = ft_strdup(&(*list)->cont[4]);
		else
			arr[y] = ft_strdup((*list)->cont);
		cur = *list;
		(*list) = (*list)->next;
		free(cur->cont);
		free(cur);
		y++;
	}
}

void	ft_read(char *name, t_fil *fl)
{
	char	*line;
	int		i;
	t_lst	*list;
	t_lst	*begin;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$')
		{
			while (line[i] != '[')
				i++;
			if (ft_strcmp(&line[i + 1], name) > 0)
				fl->symb = 'O';
			else
				fl->symb = 'X';
		}
		if (ft_isdigit(line[0]) && ++fl->my)
			ft_createlist(&list, line);
		if ((line[0] == '*' || line[0] == '.') &&  ++fl->ty)
			ft_createlist(&begin, line);
		if (line[0] == '<')
		{
			free(line);
			break ;
		}
		free(line);
	}
	ft_map_token(&list, fl, fl->map);
	ft_map_token(&begin, fl, fl->token);
}

int main(int argc, char **argv)
{
	t_fil	*fl;

	fl->mx = 0;
	fl->my = 0;
	fl->tx = 0;
	fl->ty = 0;
	if(!(fl = (t_fil *)malloc(sizeof(*fl))))
		perror("Error");
	ft_read(argv[0], fl);
	return (0);
}
