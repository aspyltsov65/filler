/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 22:34:05 by apyltsov          #+#    #+#             */
/*   Updated: 2018/04/22 22:34:08 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_algor(t_fil *fl)
{
	int	i;
	int	j;
	int	k = -1;
	int	n = -1;
	int r1;
	int	r2;
	int	l;
	int x;
	int	y;

	i = -1;
	l = fl->my + fl->mx;
	dprintf(2, "symb %c\n", fl->symb);
	while (++i < fl->my)
	{
		j = -1;
		while (++j < fl->mx)
		{
			if (fl->map[i][j] != '.' && fl->map[i][j] != fl->symb)
			{
				k = i;
				n = j;
				break;
			}
		}
		if (k != -1)
			break;
	}
	dprintf(2, "\n\n\n hello \n");
	dprintf(2, "finish k %d n %d\n\n", k, n);
	i = -1;
	while (++i < fl->my)
	{
		j = -1;
		while (++j < fl->mx)
		{
			if ((fl->map[i][j] == '.' || fl->map[i][j] == fl->symb) 
			&& (i + fl->ty <= fl->my) && (j + fl->tx <= fl->mx))
			{
				//dprintf(2, "\n hi \n\n\n");
				if (ft_check(fl, i, j) == 1)
				{
					dprintf(2, "\n\n\n darov \n\n\n");
					r1 = ((k - i) < 0 ? (k - i) * (-1) : (k - i));
					r2 = ((n - j) < 0 ? (n - j) * (-1) : (n - j));
					if (r1 + r2 < l)
					{
						l = r1 + r2;
						x = i;
						y = j; 
					}
				}
			}
		}
	}
	//printf("%d %d\n", x, y);
	//dprintf(2, "\n\nx and y%d %d\n", x, y);
}

int	ft_check(t_fil *fl, int i, int j)
{
	int	count;
	int	x;
	int	y;
	int	k;

	count = 0;
	x = -1;
	k = i;
	//dprintf(2, "\n\nfl->ty %d fl->tx %d\n", fl->ty, fl->tx);
	while (++x < fl->tx)
	{
		y = -1;
		while (++y < fl->ty)
			if (fl->token[y][x] == '*')
				break ;
		if (fl->token[y][x] == '*') //this is wrong 
			break ;
	}
	dprintf(2, "y %d x %d\n", y, x);
	while (x++ < fl->tx && j < fl->mx)
	{
		i = k;
		while (y++ < fl->ty && i < fl->my)
		{
			//dprintf(2, "hello\n\n");
			if (fl->map[i][j] && (fl->map[i][j] != '.' ||
			fl->map[i][j] != fl->symb))
			{
				if (fl->map[i++][j] == fl->symb)
					count++;
			}
			else
				return (0);
		}
		y = 0;
		j++;
	}
	//dprintf(2, "\n\ni %d j %d count %d\n\n", i, j, count);
	return (count == 1 ? 1 : 0);
}

