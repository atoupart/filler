/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_position2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 05:40:32 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/10 05:40:34 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int			search_position2(t_struct *s, int y1, int x1)
{
	int	py;
	int px;
	int pxx;

	int nb;
	int nb_star;
	// fprintf(stderr, "\033[93m>Y1 = %d\n", y1);
	// fprintf(stderr, "\033[93m>X1 = %d\n", x1);

	//fprintf(stderr, "\033[93m====================>entre dans search position2\n");

	s->j = 0;
	s->height = height_piece(s) - 1;
	//fprintf(stderr, "s->height = %d\n", s->height + 1);
	py = find_first_star(s, 0);
	px = find_apleft(s);
	//fprintf(stderr, "\033[96mPX = %d!!!!!!\n", px);

	find_last_star(s, s->yp - 1);
	// pxx = s->app;
	pxx = s->app;
	s->j = 0;
	while (s->height - s->j  > py - 1)
	{
		find_first_star(s, s->height - s->j);
		find_last_star(s, s->height - s->j);
		nb_star = nb_star_line(s, s->height - s->j);
		nb = 0;
		s->i = 0;

		 s->ecart = s->app - pxx;
		//fprintf(stderr, "\033[93ms->ecart = s->app - px\n");
		//fprintf(stderr, "\033[93m%d = %d - %d\n", s->app - pxx, s->app, pxx);


		//fprintf(stderr, "\033[93m########################################################################\n");
		//fprintf(stderr, "\033[93mnb_star = %d pour ligne piece = %d\n", nb_star, s->height - s->j);
		while (nb < nb_star)
		{			
			//fprintf(stderr, "\033[93m@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			while (s->piece[s->height - s->j][s->app - s->i] != '*')
			{
				 //fprintf(stderr, "\033[93mpasse dans boucle nb  = %d \n", nb);

				s->i++;
			}
			//fprintf(stderr, "\033[93m s->height - s->j = op && s->app - s->i = ap\n");
			//fprintf(stderr, "\033[93m %d    -    %d    =     %d   &&   %d   -   %d   =   %d\n", s->height, s->j, s->height - s->j, s->app , s->i, s->app - s->i);
			//fprintf(stderr, "\033[97mpoint referenciel piece[%d][%d]\n", s->height - s->j, s->app - s->i);
			if (verif_piece_posable2(s, y1, x1) == 1)
			{
				//fprintf(stderr, "\033[93ms->diff_h = %d\n", s->diff_h);
				//fprintf(stderr, "\033[93ms->diff_l = %d\n", s->diff_l);
				//fprintf(stderr, "\033[91ms->y1 = y1 - s->diff_h - py + s->j\n");
				//fprintf(stderr, "\033[91ms->y1 = %d - %d - %d + %d\n", y1, s->diff_h, py, s->j);
				//fprintf(stderr, "\033[91m--->s->y1 = %d\n\n", y1 - s->diff_h - py + s->j);
				//fprintf(stderr, "\033[92ms->x1 = x1 - s->diff_l - px + s->i - s->ecart\n");
				//fprintf(stderr, "\033[92ms->x1 = %d - %d - %d + %d - %d\n",  x1, s->diff_l, px, s->i, s->ecart);
				//fprintf(stderr, "\033[92m--->s->x1 = %d\n", x1 - s->diff_l - px + s->i - s->ecart);
				// //fprintf(stderr, "\033[96ms->ecart = %d\n", s->ecart);

				s->y1 = y1 - s->diff_h - py + s->j;
				s->x1 = x1 - s->diff_l - px + s->i - s->ecart;
				 	//fprintf(stderr, "\033[95mpour initial y1 = %d\npour initial x1 = %d\n", y1, x1);
			

				// fprintf(stderr, "\033[97m >>IN SEARCH_POSITION 2 with plateau[%d][%d]\n", y1, x1);

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

int		verif_piece_posable2(t_struct *s, int y1, int x1)
{
	int j;
	int px2;


	//fprintf(stderr, "\033[92m------------------------------>entre dans verif piece2\n");
	s->op = find_first_star(s, 0);
	px2 = find_apleft(s);
	j = 0;
	while (s->op + j < s->height + 1)
	{
		find_first_star(s, s->op + j);
		s->diff = s->ap - px2;
		//fprintf(stderr, "\033[92ms->diff = s->ap - px2\n");

		//fprintf(stderr, "\033[92ms->diff = %d = %d - %d\n", s->ap - px2, s->ap, px2);
		//fprintf(stderr, "\033[92mverif_line = %d\n", s->op + j);
		if (verif_line_piece2(s, j, y1, x1) == 1)
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

int		verif_line_piece2(t_struct *s, int j, int y1, int x1)
{
	int		nb_star;
	int nb;
	int i;

	//fprintf(stderr, "\033[95m++++++++++++++++++++++++++++++++++++++++>verif_pose2\n");

	nb_star = nb_star_line(s, s->op + j);
	nb = 0;
	i = 0;

	int x;
	int y;
	int px;
	int py;

	y = y1 + j + s->j - s->diff_h;
	py = s->op + j;
	//fprintf(stderr, "\033[89my = y1 + j -  s->j  - s->diff_h\n");
	//fprintf(stderr, "\033[89m%d =   %d    +    %d   -   %d  - %d\n", y ,  y1, j, s->j,  s->diff_h);


	while (nb < nb_star)
	{								
		x = x1 + i + s->diff +  s->i  - s->diff_l - s->ecart;
		px = s->ap + i;
		//fprintf(stderr, "\033[96mpour ligne piece %d nb_star = %d et nb = %d\n", py, nb_star, nb);
		//fprintf(stderr, "\033[96mx = x1 + i + s->diff + s->i  - s_>diff_l - s->ecart\n");
		//fprintf(stderr, "\033[96m%d =   %d  + %d +  %d +  %d   - %d  -  %d\n", x, x1, i, s->diff, s->i, s->diff_l, s->ecart);



		if (y < 0 || x < 0 || !s->plateau[y][x] || !s->piece[py][px])
		{
			//fprintf(stderr, "\033[94m en plateau[%d][%d] ou enpiece[%d][%d] n'existe pas\n", y, x, py, px);
			//fprintf(stderr, "\033[94m>>>>>>>>>>>>>>>>>>return (0) numero 1<<<<<<<<<<<<<<<<<<\n\n");
			s->ok_star = 0;
			return (0);
		}
		while (s->piece[py][px] != '*')
		{

			i++;
			//fprintf(stderr, "\033[93mpassage dans boucle passeur de . \n");
			x = x1 + i + s->diff + s->i - s->ecart - s->diff_l;
			px = s->ap + i;


		}	

		//fprintf(stderr, "\033[97m en plateau[%d][%d] il est verifier piece piece[%d][%d] \n", y, x, py, px);

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
			//fprintf(stderr, "\033[96m>>>>>>>>>>>>>>>>>>return (0) numero 2<<<<<<<<<<<<<<<<<<\n\n");
			return (0);
		}
		nb++;
	}
	//fprintf(stderr, "\033[91mToutes les * de la ligne trouvé!\n\033[0m");
	//fprintf(stderr, "\033[91mreturn (1)\n\n\033[0m");

	return (1);
}

