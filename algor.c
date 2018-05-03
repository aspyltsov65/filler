/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:28:01 by apyltsov          #+#    #+#             */
/*   Updated: 2018/05/03 13:28:08 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
void	ft_algoritm(t_fil *fl)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	l;
	int	r1;
	int	r2;
	int	k;
	int	n;

	i = -1;
	while (++i < fl->my)
	{
		j = -1;
		while (++j < fl->mx)
			if (fl->map[i][j] != '.' && fl->map[i][j] != fl->symb)
				break ;
		if (j != fl->mx)
			break;
	}
	// dprintf(2, "fl->my %d fl->mx %d\n", fl->my, fl->mx);
	// dprintf(2, "\ni %d j %d\n", i, j);
	l = fl->mx + fl->my;
	y = -1;
	while (++y < fl->my)
	{
		x = -1;
		while (++x < fl->mx)
		{
			if (fl->map[y][x] == fl->symb || fl->map[y][x] == '.')
			{
				if(ft_check(fl, y, x) == 1)
				{
					dprintf(2, "hello\n");
					r1 = (i - y < 0 ? (i - y) * (-1) : i + y);
					r2 = (j - x < 0 ? (j - x) * (-1) : j + x);
					if (r1 + r2 < l)
					{
						l = r1 + r2;
						k = x;
						n = y;
					}
				}
			}
		}
	}
	dprintf(2, "my cootdinate %d %d\n", k, n);
	printf("%d %d\n", k, n);
}

int		ft_check(t_fil *fl, int y, int x)
{
	int	count;

	count = 0;
	while (fl->tj < fl->tx && x < fl->mx)
	{
		while (fl->ti < fl->ty && y < fl->my)
		{
			dprintf(2, "darov\n");
			if(fl->token[fl->ti++][fl->tj++] == '*' && fl->map[y][x] &&
			(fl->map[y][x] == '.' || fl->map[y][x] == fl->symb))
			{
				dprintf(2, "privetik\n");
				if (fl->map[y++][x] == fl->symb)
				{
					dprintf(2, "ya tyt\n");
					count++;
				}
			}
			else
				return (0);
		}
		fl->ti = 0;
		x++;
	}
	return (count == 1 ? 1 : 0);
}

















