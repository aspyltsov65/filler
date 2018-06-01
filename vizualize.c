/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:19:33 by apyltsov          #+#    #+#             */
/*   Updated: 2018/05/19 16:19:36 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_color(t_bon *fl, int i, int j, WINDOW *playwin)
{
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	if (fl->map[i][j] == 'X' || fl->map[i][j] == 'x')
	{
		wattron(playwin, COLOR_PAIR(1));
		mvwprintw(playwin, i + 1, j + 1, " ");
		wattroff(playwin, COLOR_PAIR(1));
	}
	else if (fl->map[i][j] == 'O' || fl->map[i][j] == 'o')
	{
		wattron(playwin, COLOR_PAIR(2));
		mvwprintw(playwin, i + 1, j + 1, " ");
		wattroff(playwin, COLOR_PAIR(2));
	}
	else
		mvwprintw(playwin, i + 1, j + 1, "%c", 46);
}

void	ft_vizualize(t_bon *fl)
{
	WINDOW	*playwin;
	int		i;
	int		j;

	playwin = newwin(fl->my + 2, fl->mx + 2, 1, 1);
	refresh();
	box(playwin, 0, 0);
	wrefresh(playwin);
	i = -1;
	while (++i < fl->my)
	{
		j = -1;
		while (++j < fl->mx)
			ft_color(fl, i, j, playwin);
	}
	wrefresh(playwin);
}

void	ft_read_for_bonus(t_list *list, t_bon *fl, int *c)
{
	int		j;
	char	*line;

	*c = fl->my;
	j = -1;
	while (++j < fl->my && get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]))
			ft_createlist(&list, &line[4]);
		free(line);
	}
	fl->my -= 1;
	fl->map = (char **)ft_memalloc(sizeof(char *) * fl->my);
	ft_parse_list(&list, fl->map);
	ft_vizualize(fl);
}

void	ft_reading(t_bon *fl, t_list *list, char *line)
{
	int	c;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau") != NULL && (c = 8))
		{
			fl->my = ft_atoi(&line[c]) + 1;
			while (ft_isdigit(line[c++]))
				;
			fl->mx = ft_atoi(&line[c]);
			ft_read_for_bonus(list, fl, &c);
		}
		if (line[0] == '=')
		{
			mvprintw(3 + fl->my, 1, "RESULT OF THE GAME:");
			init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
			init_pair(2, COLOR_BLUE, COLOR_BLUE);
			if (ft_strstr(line, "X") != NULL)
				mvaddch(4 + c, 1, ' ' | COLOR_PAIR(1));
			else
				mvaddch(4 + c, 1, ' ' | COLOR_PAIR(2));
			mvprintw(4 + c++, 2, "  %s\n", line);
		}
		free(line);
	}
}

int		main(void)
{
	t_bon	*fl;
	char	*line;
	t_list	*list;
	WINDOW	*stdsrc;

	stdsrc = initscr();
	if (!(fl = (t_bon *)malloc(sizeof(*fl))))
		perror("Error");
	attron(A_BOLD);
	mvprintw(0, 1, "START OF THE GAME:\n");
	fl->mx = 0;
	fl->my = 0;
	list = NULL;
	get_next_line(0, &line);
	fl->name = (ft_strstr(line, "p1") != NULL ? 2 : 1);
	free(line);
	system("say Start of the game");
	ft_reading(fl, list, line);
	system("say Result of the game");
	nodelay(stdsrc, FALSE);
	if (getch() != -1)
		endwin();
	return (0);
}
