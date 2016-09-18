/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:35:36 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/10 02:35:38 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int		calcul2(int y1, int x1, int y2, int x2)
{
	int result;

// fprintf(stderr, "y1 = %d\nx1 = %d\ny2 = %d\nx2 = %d\n", y1, x1, y2, x2);

	result = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	// fprintf(stderr, "result = %d\n", result);

	return (result);
}
int find_apleft(t_struct *s)
{
	int apleft;
	int op;

	apleft = 0;
	while (apleft < s->xp)
	{
		op = 0;
		while (op < s->yp)
		{
			if (s->piece[op][apleft] == '*')
				return (apleft);
			op++;
		}
		apleft++;
	}
	return (0);
}

int			find_opdown(t_struct *s)
{
	int opdown;
	int ap;
	
	opdown = s->yp -1;
	while (opdown > -1)
	{
		ap = 0;
		while (ap < s->xp)
		{
			if (s->piece[opdown][ap] == '*')
				return (opdown);
			ap++;
		}
		opdown--;
	}
	return (0);
}

void		orientate_piece(t_struct *s)
{
	int opdown;
	int opup;
	int apgauche;

	opdown = find_opdown(s);
	apgauche = find_apleft(s);
	opup = find_first_star(s, 0);
	find_last_star(s, s->yp - 1);
	

	s->diff_h = opdown - opup;
	s->diff_l = s->app - apgauche;
	// fprintf(stderr, "s->diff_h = opdown - opup\n");
	// fprintf(stderr, "%d = %d - %d\n", opdown - opup, opdown, opup);
	// fprintf(stderr, "s->diff_l = s->app - apgauche\n");
	// fprintf(stderr, "%d = %d - %d\n", s->app - apgauche, s->app, apgauche);



	// fprintf(stderr, " first s->y1= %d \nfirst s->x1 = %d\n", s->y1, s->x1);
	// fprintf(stderr, " first s->y2= %d \nfirst s->x2 = %d\n", s->y2, s->x2);

	
	s->res_orient = calcul2( s->y1 - s->diff_h, s->x1 - s->diff_l, s->y2, s->x2);
	s->res_orient2 = calcul2( s->y1, s->x1 , s->y2, s->x2);
	
	// fprintf(stderr, "-->res_orient = %d\n===>res_orient2 = %d\n", s->res_orient, s->res_orient2);
	

	if (s->res_orient > s->res_orient2)
	{

		s->diff_h = 0;
		s->diff_l = 0;
	}
	else  //debug
	{
		fprintf(stderr, "ORIENTATION CHANGED\n");

	}
}


