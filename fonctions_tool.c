/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:33:18 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/03 16:33:21 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_piece(t_struct *s)
{
	if (s->ver == 0)
		fprintf(stderr, "\033[92mver  = 0 Print depuis search basique\n");
	else if (s->ver == 1)
		fprintf(stderr, "\033[92mver  = 1 Print depuis touch_opponent\n");
	else if (s->ver == 2)
		fprintf(stderr, "\033[92mver  = 2 Print depuis test_around\n");	
	else if (s->ver == 3)
		fprintf(stderr, "\033[96#############################################mver  = 3 Print depuis parcour_point_hg\n");
	else if (s->ver == 4)
		fprintf(stderr, "\033[91m############################################ver  = 4 Print depuis parcour_point_bd\n");
	// else if (s->ver == 5)
	// 	fprintf(stderr, "\033[92mver  = 5 Print depuis parcour_point_hd\n");


	fprintf(stderr, "\033[92m===>Y1 = %d\n", s->y1);
	fprintf(stderr, "\033[92m===>X1 = %d\n", s->x1);


	ft_putnbr(s->y1);
	ft_putchar(' ');
	ft_putnbr(s->x1);
	ft_putchar('\n');
}

int height_piece(t_struct *s)
{
	int i;
	int j;
	int x;

	i = 0;
	j = s->yp;
	while (j > 0)
	{
		x = 0;
		while (x < s->xp)
		{
			if (s->piece[j - 1][x] == '*')
				return (s->yp - i);
			x++;
		}
		i++;
		j--;
	}
	return (0);
}

int	nb_star_line(t_struct *s, int py)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s->piece[py][i])
	{
		if (s->piece[py][i] == '*')
			nb++;
		i++;
	}
	return (nb);
}

int		find_first_star(t_struct *s, int opj)
{
	while (opj < s->yp)
	{
		s->ap = 0;
		while (s->ap < s->xp)
		{
			if (s->piece[opj][s->ap] == '*')
				return (opj);
			s->ap++;
		}
		opj++;
	}
	return (0);
}

int		find_last_star(t_struct *s, int opj)
{
	while (opj >= 0)
	{
		s->app = s->xp - 1;
		while (s->app >= 0)
		{
			if (s->piece[opj][s->app] == '*')
				return (opj);
			s->app--;
		}
		opj--;
	}
	return (0);
}
