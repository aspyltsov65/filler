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
		fl->cord[1] = 0;
	}
	ft_putnbr_fd(fl->cord[0], 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(ft_itoa(fl->cord[1]), 1);
	fl->cord[0] = 0;
	fl->cord[1] = 0;
	fl->sum = 0;
}

int		ft_check(t_fil *fl, int y, int x, int sum)
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
		else if (fl->map[y + fl->c_y[n]][x + fl->c_x[n]] != fl->enemy &&
		fl->map[y + fl->c_y[n]][x + fl->c_x[n]] != ft_tolower(fl->enemy))
			sum += fl->map[y + fl->c_y[n]][x + fl->c_x[n]];
		else
			return (0);
	}
	return (i == 1 ? sum : 0);
}

void	ft_rec(t_fil *fl, char s, int count, int n)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fl->my)
	{
		x = -1;
		while (++x < fl->mx)
		{
			if ((fl->map[y][x] == s || fl->map[y][x] == s + 32) && ++n)
			{
				if ((x - 1) >= 0 && fl->map[y][x - 1] == '.')
					fl->map[y][x - 1] = count;
				if ((x + 1) < fl->mx && fl->map[y][x + 1] == '.')
					fl->map[y][x + 1] = count;
				if ((y - 1) >= 0 && fl->map[y - 1][x] == '.')
					fl->map[y - 1][x] = count;
				if ((y + 1) < fl->my && fl->map[y + 1][x] == '.')
					fl->map[y + 1][x] = count;
			}
		}
	}
	if (n)
		ft_rec(fl, count, count + 1, 0);
}

void	ft_algoritm(t_fil *fl)
{
	int	count;
	int	y;
	int	x;
	int	t;

	count = 1;
	fl->symb == 'X' ? ft_rec(fl, 'O', count, 0) : ft_rec(fl, 'X', count, 0);
	count = 0;
	y = -1;
	while (++y < fl->my)
	{
		x = -1;
		while (++x < fl->mx)
		{
			t = ft_check(fl, y, x, 0);
			fl->sum = (fl->sum == 0 && t > 0 ? t : fl->sum);
			if (t > 0 && t <= fl->sum && ++count)
			{
				fl->sum = t;
				fl->cord[0] = y;
				fl->cord[1] = x;
			}
		}
	}
	ft_result(fl, count);
}
