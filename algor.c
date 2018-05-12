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
	int	cord[2];
	int	count;

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
	l = fl->mx + fl->my;
	count = 0;
	y = -1;
	while (++y < fl->my)
	{
		x = -1;
		while (++x < fl->mx)
		{
			if(ft_check(fl, y, x) == 1)
			{
				r1 = (i - y < 0 ? (i - y) * (-1) : i - y);
				r2 = (j - x < 0 ? (j - x) * (-1) : j - x);
				if (r1 + r2 < l)
				{
					l = r1 + r2;
					cord[0] = x;
					cord[1] = y;
				}
				count++;
			}
		}
	}
	if (count == 0)
	{
		cord[0] = 0;
		cord[1] = 0;
	}
	ft_putnbr_fd(cord[1], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(cord[0], 1);
	ft_putchar_fd('\n', 1);

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

















