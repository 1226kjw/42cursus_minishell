/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:15:07 by ji-kim            #+#    #+#             */
/*   Updated: 2021/07/05 15:16:08 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig_handler.h"

extern int	g_ret;

void		sig_handler(int sig)
{
	if (sig)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		// rl_redisplay();
	}
	g_ret = 1;
}

void		sig_handler2(int sig)
{
	if (sig)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_ret = 1;
}

void		set_termios(int i)
{
	struct termios	t_new;

	tcgetattr(0, &t_new);
	if (!i)
		t_new.c_lflag &= ~(ECHOCTL);
	else
	{
		t_new.c_lflag &= ~(ICANON | ECHO);
		t_new.c_cc[VMIN] = 1;
		t_new.c_cc[VTIME] = 0;
	}
	tcsetattr(0, TCSANOW, &t_new);
}

void		get_cursor_position(int *col, int *rows)
{
	int		a;
	int		i;
	char	buf[254];

	a = 0;
	i = -1;
	write(1, CLEAR_LINE, 4);
	read(1, buf, 254);
	while (buf[++i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*rows = ft_atoi(&buf[i]) - 1;
			else
			{
				*col = ft_atoi(&buf[i]) - 1;
			}
			a++;
		}
	}
}

void		set_line(int col, int row, char *cm, char *ce)
{
	tputs(tgoto(cm, col, row - 1), 1, ft_putchar);
	tputs(ce, 1, ft_putchar);
}

int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void		set_termcap(int flag)
{
	char	*cm;
	char	*ce;
	int		col;
	int		row;

	set_termios(1);
	tgetent(NULL, "xterm");
	cm  = tgetstr("cm", NULL);
	ce  = tgetstr("ce", NULL);
	get_cursor_position(&col, &row);
	col = flag;
	set_line(col, row, cm, ce);
}
