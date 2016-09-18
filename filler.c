/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 19:59:48 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/22 19:59:59 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void		ft_putstr_color(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'O')
			ft_putstr_fd("\033[95mO\033[0m", 2);
		else if (str[i] == 'o')
			ft_putstr_fd("\033[95mo\033[0m", 2);
		else if (str[i] == 'X')
			ft_putstr_fd("\033[96mX\033[0m", 2);
		else if (str[i] == 'x')
			ft_putstr_fd("\033[96mx\033[0m", 2);
		else
			write(2, &str[i], 1);

	}
	ft_putchar_fd('\n', 2);
}
int			main()
{

	int i;
	int k;
	int xrim;
	int yrim;
		int u;
		int h;
		int d;
	char	*str;
	t_struct s;

	ft_bzero(&s, sizeof(t_struct));
	str = NULL;
	i= -1;
	k = 1;

		int a;
		int b;
		int yinit;
		int xinit;

	u = 0;
	while (42)
	{
		// sleep(1);
		i++;
		k *= -1;

		fprintf(stderr, "###########################################>%d\n", i);
		fprintf(stderr, " k = %d\n", k);
		
		if (s.player == 0 || s.plateau == NULL)
			init_player_plateau(&s, str);
		else
		{
			get_next_line(0, &str);
			// fprintf(stderr, "%s\n", str);
			ft_putstr_color(str);
			if (*str == '\0')
			{
				fprintf(stderr, "\033[94mEND OF POSSIBILITIES\n");
				return (0);
			}

		}
		determine_plateau(&s, str);
		determine_piece(&s, str);



		if (i == 0)
		{
			find_point_player_bg(&s);
			xinit = s.x1;
			yinit = s.y1;

			if (s.y1 > s.y - s.y1)
				a = s.y - s.y1;
			else
				a = s.y;

			if (s.x1 > s.x - s.x1)
				b = s.x - s.x1;
			else
				b = s.x;
			if ( s.y1 < s.y / 2)
			{	
				if (a <= b)
				{
					yrim = 0;
					xrim = s.x1;				
				}
				else
				{
					yrim = s.y1;
					xrim = 0;
				}
			}
			else
			{
				if (a <= b)
				{
					yrim = s.y - 1;
					xrim = s.x1;				
				}
				else
				{
					yrim = s.y1;
					xrim = s.x -1;
				}
			}
		}






		if ( d == 0)
		{
			u = 0;
			while (u <= s.y - 1)
			{
				// fprintf(stderr, "\033[94m ########## u = %d\n", u);

				h = 0;
				while (h <= s.x - 1)
				{
					// fprintf(stderr, "\033[94mh = %d\n", h);

					if (s.plateau[u][h] == s.l_player)
					{
						if (u == 0 || u == s.y -1 || h == 0 || h == s.x -1)
						{
							d = 1;
							break;
						}
					}
					h++;
				}
				if (d == 1)
					break;
				u++;
			}
		}

		fprintf(stderr, "\033[94m D = %d\n", d);
		fprintf(stderr, "\033[94m k = %d\n", k);



		if (d == 0 && k < 0)
		{
			s.x1 = xinit;
			s.y1 = yinit;
			s.x2 = xrim;
			s.y2 = yrim;

			fprintf(stderr, "\033[91m Yinit = %d\n", yinit);
			fprintf(stderr, "\033[91m Xinit = %d\n", xinit);
			fprintf(stderr, "\033[91m YRIM = %d\n", yrim);
			fprintf(stderr, "\033[91m XRIM = %d\n", xrim);
		}
		else
		{
			if (k < 0)
			{
				find_point_player_hg(&s);
				find_point_opponent_hg(&s);
				fprintf(stderr, "\033[97m in k<0 hg y1= %d\n", s.y1);
				fprintf(stderr, "\033[97m in k<0 hg x1= %d\n", s.x1);
				fprintf(stderr, "\033[97m in k<0 hg y2= %d\n", s.y2);
				fprintf(stderr, "\033[97m in k<0 hg x2= %d\n", s.x2);


			}
			else
			{
				find_point_player_bd(&s);
				find_point_opponent_bd(&s);
				fprintf(stderr, "\033[97m in k>0 bd y1= %d\n", s.y1);
				fprintf(stderr, "\033[97m in k>0 bd x1= %d\n", s.x1);
				fprintf(stderr, "\033[97m in k>0 bd y2= %d\n", s.y2);
				fprintf(stderr, "\033[97m in k>0 bd x2= %d\n", s.x2);
			}
		}

		// if (k < 0)
		// {
		// 	find_point_player_hg(&s);
		// 	find_point_opponent_hg(&s);
		// }
		// else
		// {
		// 	find_point_player_bd(&s);
		// 	find_point_opponent_bd(&s);
		// }



			// if (l < 0)
		// 	l = find_direction(&s, l);

		// indicate_direction(&s, l, k);
		// indicate_direction2(&s, l, k);

		recursive_find_best_points(&s);
		s.ver = 0;
		fprintf(stderr, "\033[93my1> %d\n", s.y1);
		fprintf(stderr, "\033[93mx1> %d\n", s.x1);


		orientate_piece(&s);
		
		if (search(&s, s.y1, s.x1) == 0)
		{
			fprintf(stderr, "\033[93msearch basique introuver, entrance in parcours\n");

			if (parcour(&s, k) == 0)
			{
				fprintf(stderr, "\033[94mPIECE IMPOSABLE\n");

				s.y1 = 0;
				s.x1 = 0;
				print_piece(&s);
			}
		}
		fprintf(stderr, "\033[94m nb_touch_opponent = %d\n", s.nb_touch_opponent);
		fprintf(stderr, "\033[94m nb_test_around = %d\n", s.nb_test_around);
		fprintf(stderr, "\033[94m nb_parcour_point_hg = %d\n", s.nb_parcour_point_hg);
		fprintf(stderr, "\033[94m nb_parcour_point_bd = %d\n", s.nb_parcour_point_bd);
		fprintf(stderr, "\033[94m nb_parcour_point_hd = %d\n", s.nb_parcour_point_hd);



		fprintf(stderr, "\033[97m-_-_-// fin boucle\n\n");
	}
	return (0);
}



