/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 11:20:51 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/13 11:20:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"



int		parcour(t_struct *s, int k)
{

	if (touch_opponent(s))
	{
		s->nb_touch_opponent++;
		return (1);
	}
	else if (test_around(s))
	{
		s->nb_test_around++;
		// fprintf(stderr, "\033[93m point test around plateau[%d][%d] \n", s->y1, s->x1);
		// fprintf(stderr, "\033[92m test_around over\n");
		return (1);
	}
	else if (k > 0 && parcour_point_hg(s))
	{
		s->nb_parcour_point_hg++;
		// fprintf(stderr, "\033[93m point HG plateau[%d][%d] \n", s->y1, s->x1);
		// fprintf(stderr, "\033[92m parcour_point_hg over\n");
		return (1);
	}
	else if (parcour_point_bd(s))
	{
		s->nb_parcour_point_bd++;

		// fprintf(stderr, "\033[93m point HD plateau[%d][%d] \n", s->y1, s->x1);
		// fprintf(stderr, "\033[92m parcour_point_hg over\n");
		return (1);
	}
	else if (parcour_point_hd(s))
	{
		s->nb_parcour_point_hd++;

		// fprintf(stderr, "\033[93m point HD plateau[%d][%d] \n", s->y1, s->x1);
		// fprintf(stderr, "\033[92m parcour_point_hg over\n");
		return (1);
	}
	return (0);
}
int			parcour_point_hg(t_struct *s)
{
	// fprintf(stderr, "\033[91m ENTER IN PARCOUR_POINT_HG \n");

	int y1;
	int x1;

	y1 = 0;
	while (y1 < s->y)
	{
		x1 = 0;
		while (x1 < s->x)
		{
			if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1) && touch_around(s, y1, x1))
			{
				s->ver = 3;

				// fprintf(stderr, "\033[93m try with point_HG plateau[%d][%d] \n", y1, x1);
				if (search(s, y1, x1))
					return (1);
			}
			x1++;
		}
		y1++;
	}
	return (0);
}

int			parcour_point_bd(t_struct *s)
{
	int y1;
	int x1;

	y1 = s->y - 1;
	while (y1 >= 0)
	{
		x1 = s->x -1;
		while (x1 >= 0)
		{
			if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1) && touch_around(s, y1, x1))
			{
				s->ver = 4;

				// fprintf(stderr, "\033[93m try with point_HG plateau[%d][%d] \n", y1, x1);
				if (search(s, y1, x1))
					return (1);
			}
			x1--;
		}
		y1--;
	}
	return (0);
}

int			parcour_point_hd(t_struct *s)
{
	// fprintf(stderr, "\033[91m ENTER IN PARCOUR_POINT_HD\n");

	int y1;
	int x1;

	y1 = 0;
	while (y1 < s->y)
	{
		x1 = s->x - 1;
		while (x1 >= 0)
		{
			if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1))
			{
				s->ver = 5;

				// fprintf(stderr, "\033[93m try with point_HD plateau[%d][%d] \n", y1, x1);
				if (search(s, y1, x1))
					return (1);
			}
			x1--;
		}
		y1++;
	}
	return (0);
}

int			test_around(t_struct *s)
{
	int i;
	int j;
	int k;
	int x1;
	int y1;


	// fprintf(stderr, "\033[91m ENTER IN TEST_AROUND \n");
	k = 1;
	while (k <= 3)
	{
		j = 0;
		while (s->y1 - k + j <= s->y1 + k)
		{
			i = 0;
			while (s->x1 - k + i <= s->x1 + k)
			{
				y1 = s->y1 - k + j;
				x1 = s->x1 - k + i;
				// fprintf(stderr, "\033[91m !!!!!!! plateau[%d][%d] \n", y1, x1);
				if (y1 > s->y - 1 || x1 > s->x - 1 || y1 < 0 || x1 < 0)
				{
					i++;
					continue;
				}
				if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1))
				{
					s->ver = 2;
					if(search(s, y1, x1))
						return (1);
				}	
				i++;
			}
			j++;
		}
	k++;
	}
	return (0);
}



int 			touch_opponent(t_struct *s)
{
	int i;
	int j;
	int k;
	int x1;
	int y1;


	// fprintf(stderr, "\033[91m ENTER IN TEST_AROUND \n");
	k = 1;
	while (k <= 10)
	{
		j = 0;
		while (s->y1 - k + j <= s->y1 + k)
		{
			i = 0;
			while (s->x1 - k + i <= s->x1 + k)
			{
				y1 = s->y1 - k + j;
				x1 = s->x1 - k + i;
				// fprintf(stderr, "\033[91m !!!!!!! plateau[%d][%d] \n", y1, x1);
				if (y1 > s->y - 1 || x1 > s->x - 1 || y1 < 0 || x1 < 0)
				{
					i++;
					continue;
				}
				if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1) && touch_around(s, y1, x1))
				{
					s->ver = 1;

					if(search(s, y1, x1))
						return (1);
				}	
				i++;
			}
			j++;
		}
	k++;
	}
	return (0);
}











































