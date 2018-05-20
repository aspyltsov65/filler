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

void	ft_result(t_fil *fl, int count)
{
	if (count == 0)
	{
		fl->cord[0] = 0;
		fl->cord[1] = 0;  \
	}
	ft_putnbr_fd(fl->cord[1], 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(ft_itoa(fl->cord[0]), 1);
}

void	ft_algor(int i, int j, t_fil *fl, int l)
{
	int	count;
	int	r[2];
	int	x;
	int	y;

	count = 0;
	y = -1;
	while (++y < fl->my)
	{
		x = -1;
		while (++x < fl->mx)
			if (ft_check(fl, y, x) == 1 && ++count)
			{
				r[0] = (i - y < 0 ? (i - y) * (-1) : i - y);
				r[1] = (j - x < 0 ? (j - x) * (-1) : j - x);
				if (r[0] + r[1] < l)
				{
					l = r[0] + r[1];
					fl->cord[0] = x;
					fl->cord[1] = y;
				}
			}
	}
	ft_result(fl, count);
}

void	ft_algoritm(t_fil *fl)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	while (++i < fl->my)
	{
		j = -1;
		while (++j < fl->mx)
			if (fl->map[i][j] != '.' && fl->map[i][j] != fl->symb)
				break ;
		if (j != fl->mx)
			break ;
	}
	l = fl->mx + fl->my;
	ft_algor(i, j, fl, l);
}

int		ft_check(t_fil *fl, int y, int x)
{
	int	n;
	int	i;
	int	k;
	int	m;

	i = 0;
	n = -1;
	while (++n < fl->count)
	{
		m = fl->c_y[n];
		k = fl->c_x[n];
		if ((y + m >= fl->my) || (x + k >= fl->mx))
			return (0);
		if (fl->map[y + m][x + k] == fl->symb ||
		fl->map[y + m][x + k] == ft_tolower(fl->symb))
			i++;
		else if (fl->map[y + fl->c_y[n]][x + fl->c_x[n]] == '.')
			;
		else
			return (0);
	}
	return (i == 1 ? 1 : 0);
}
