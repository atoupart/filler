/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 10:20:13 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/02 10:20:18 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			search_position(t_struct *s, int y1, int x1)
{
	int	py;
	int px;

	int nb;
	int nb_star;
	 // fprintf(stderr, "\033[93m>Y1 = %d\n", y1);
	 // fprintf(stderr, "\033[93m>X1 = %d\n", x1);

	 //fprintf(stderr, "\033[93m====================>entre dans search position\n");

	s->j = 0;
	s->height = height_piece(s);
	 //fprintf(stderr, "s->height = %d\n", s->height);
	py = find_first_star(s, 0);
	px = s->ap;
	while (py + s->j < s->height)
	{
		find_first_star(s, py + s->j);
		nb_star = nb_star_line(s, py + s->j);
		s->app = s->ap;
		nb = 0;
		s->i = 0;

		s->ecart = s->app - px;

		 //fprintf(stderr, "\033[93m########################################################################\n");
		 //fprintf(stderr, "\033[93mnb_star = %d pour ligne piece = %d\n", nb_star, py + s->j);
		while (nb < nb_star)
		{			
			 //fprintf(stderr, "\033[93m@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			while (s->piece[py + s->j][s->app + s->i] != '*')
				s->i++;
			 //fprintf(stderr, "\033[93m py = %d  s->j = %d  s->app = %d  s->i = %d\n", py, s->j, s->app , s->i);
			 //fprintf(stderr, "\033[93m point referenciel piece[%d][%d]\n", py + s->j, s->app + s->i);
			if (verif_piece_posable(s, y1, x1) == 1)
			{
				 //fprintf(stderr, "\033[93ms->y1 -= (py + s->j)\n");
				 //fprintf(stderr, "\033[93m%d -= (%d + %d)\n", s->y1, py, s->j);
				 //fprintf(stderr, "\033[93m--->s->y1 = %d\n", s->y1  - py + s->j);
				 //fprintf(stderr, "\033[96ms->x1 -= (s->app + s->i)\n");
				 //fprintf(stderr, "\033[96m%d -= (%d + %d)\n", s->x1, s->app, s->i);
				 //fprintf(stderr, "\033[96m--->s->x1 = %d\n", s->x1 - s->app + s->i);
				s->y1 = y1 - (py + s->j);
				s->x1 = x1 - (s->app + s->i);
			 	//fprintf(stderr, "\033[95mpour initial y1 = %d\npour initial x1 = %d\n", y1, x1);
		

		// fprintf(stderr, "\033[97m >>IN SEARCH_POSITION with plateau[%d][%d]\n", y1, x1);

				return (1);
			}
			else
			{
				nb++;
				s->i++;
			}
		}
		s->j++;
	}
	return (0);
}

int		verif_piece_posable(t_struct *s, int y1, int x1)
{
	int j;
	int py2;
	int px2;


	 //fprintf(stderr, "\033[92m------------------------------------------------->entre dans verif_piece_posable\n");
	s->op = find_first_star(s, 0);
	py2 = s->op;
	px2 = s->ap;
	j = 0;
	while (s->op + j < s->height)
	{
		find_first_star(s, s->op + j);
		s->diff = s->ap - px2;
		 //fprintf(stderr, "\033[92mverif_line = %d   pour s->ap = %d ET s->diff = %d\n\n\033[0m",  s->op + j, s->ap, s->diff);
		if (verif_line_piece(s, j, y1, x1) == 1)
			j++;
		else
			return (0);
	}
	if (s->ok_star == 0)
	{
		 //fprintf(stderr, "\033[97mSTAR NON CHEVAUCHER\n");
		return (0);
	}
	return (1);
}

int		verif_line_piece(t_struct *s, int j, int y1, int x1)
{
	int		nb_star;
	int nb;
	int i;

	 //fprintf(stderr, "\033[94m=================================================> entre dans verif_line_piece \n");

	nb_star = nb_star_line(s, s->op + j);
	nb = 0;
	i = 0;

	int x;
	int y;
	int px;
	int py;

	y = y1 + j - s->j;
	py = s->op + j;

	 //fprintf(stderr, "\033[89my = %d, j = %d, s->j = %d\n", y, j, s->j);


	while (nb < nb_star)
	{	
		x = x1 + i + s->diff -  s->i - s->ecart;
		px = s->ap + i;
		 //fprintf(stderr, "\033[92mx = %d, i = %d s->diff = %d, s->i = %d, s->ecart = %d, \n", x, s->diff, i,  s->i, s->ecart);

		 //fprintf(stderr, "\033[92m en plateau[%d][%d] il est verifier piece piece[%d][%d] \n", y, x, py, px);

		if (y < 0 || x < 0 || (!s->plateau[y] && !s->plateau[y][x]) || (!s->piece[py] && !s->piece[py][px]))
		{
			s->ok_star = 0;

			 //fprintf(stderr, "\033[91m en plateau[%d][%d] ou enpiece[%d][%d] n'existe pas\n", y, x, py, px);
			 //fprintf(stderr, "\033[91m>>>>>>>>>>>>>>>>>>return (0) numero 1<<<<<<<<<<<<<<<<<<\n\n");
			return (0);
		}

		while (s->piece[py][px] != '*')
		{

			i++;
			 //fprintf(stderr, "\033[92mpassage dans boucle passeur de . \n");
			x = x1 + i + s->diff -  s->i - s->ecart;
			px = s->ap + i;


		}

		if (y == y1 && x == x1 && s->piece[py][px] == '*')
		{	
			s->ok_star = 1;
			 //fprintf(stderr, "\033[97mONLY PIECE *X TROUVER \n");
			i++;
		}
		else if (s->piece[py][px] == '*' && s->plateau[y][x] == '.')
			i++;
		else
		{
			s->ok_star = 0;
			 //fprintf(stderr, "\033[91m>>>>>>>>>>>>>>>>>>return (0) numero 2<<<<<<<<<<<<<<<<<<\n\n");
			return (0);
		}
		nb++;
	}
	 //fprintf(stderr, "\033[91mToutes les * de la ligne trouvé!\n\033[0m");
	 //fprintf(stderr, "\033[91mreturn (1)\n\n\033[0m");

	return (1);
}

