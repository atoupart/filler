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

void			free_piece(t_struct *s)
{
	int i;

	i = 0;
	while (i < s->yp + 1)
	{
		ft_strdel(&s->piece[i]);
		i++;
	}
	free(s->piece);
}

void			free_all(t_struct *s)
{
	int i;

	i = 0;
	while (i < s->y + 1)
	{
		ft_strdel(&s->plateau[i]);
		i++;
	}
	free(s->plateau);
	free_piece(s);
}

void			determine_carli(t_struct *s, int i, int k)
{
	if ( i == 0)
	{
		find_point_player_hg(s);
		find_point_opponent_hg(s);
		s->xinit = s->x1;
		s->yinit = s->y1;
		s->x2init = s->x2;
		s->y2init = s->y2;
	}
	if (s->yinit < s->y / 2)
	{
		if (s->xinit < s->x / 2)
			carli_style_hg(s, k);
		else
			carli_style_hd(s, k);
	}
	else
	{
		if (s->xinit < s->x / 2)
			carli_style_bg(s, k);
		else
			carli_style_bd(s, k);		
	}
	recursive_find_best_points(s);
	orientate_piece(s);
}

void			make_filler(t_struct *s, int k, int i)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	determine_plateau(s);
	determine_piece(s, str, tmp);
	determine_carli(s, i, k);
	if (search(s, s->y1, s->x1) == 0)
	{	
		if (parcour(s, k) == 0)
		{
			s->y1 = 0;
			s->x1 = 0;
			print_piece(s);
		}
	}
}

int				thank_norm(t_struct *s, char *str)
{
	s->ret = get_next_line(0, &str);
	if (s->ret == 0)
	{
		ft_strdel(&str);
		free_all(s);
		return (0);
	}
	free_piece(s);
	ft_strdel(&str);
	return (1);
}

int				main(void)
{
	int			i;
	int			k;
	char		*str;
	t_struct	s;

	ft_bzero(&s, sizeof(t_struct));
	str = NULL;
	i = -1;
	k = 1;
	while (42)
	{
		// sleep(1);
		i++;
		k *= -1;
		fprintf(stderr, "piece posé = %d\n", i);
		if (s.player == 0 || s.plateau == NULL)
			init_player_plateau(&s);
		else if (!thank_norm(&s, str))
			return (0);
		make_filler(&s, k, i);
	}
	return (0);
}
