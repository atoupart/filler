/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:20:51 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/25 16:20:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_player(t_struct *s)
{
	if (s->player == 1)
	{
		s->l_player = 'O';
		s->l_opponent = 'X';
		s->l_opponent2 = 'x';
	}
	else
	{
		s->l_player = 'X';
		s->l_opponent = 'O';
		s->l_opponent2 = 'o';
	}
}

void		init_player_plateau(t_struct *s)
{
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	get_next_line(0, &str);
	s->player = ft_strstr(str, "p1") ? 1 : 2;
	ft_strdel(&str);
	init_player(s);
	get_next_line(0, &str);
	tmp = str;
	if (ft_strstr(str, "Plateau"))
	{
		while (!(ft_isdigit(*str)))
			str++;
		s->y = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		s->x = ft_atoi(str);
		s->plateau = (char**)ft_memalloc(sizeof(char*) * (s->y + 1));
		while (i < s->y + 1)
			s->plateau[i++] = (char*)ft_memalloc(sizeof(char) * (s->x + 1));
	}
	ft_strdel(&tmp);
}

void		determine_plateau(t_struct *s)
{
	char *str;
	int		i;
	int		j;
	int		k;

	j = 0;
	get_next_line(0, &str);
	ft_strdel(&str);
	while (j < s->y)
	{
		get_next_line(0, &str);
		i = 0;
		k = 0;
		while (str[i] != ' ')
			i++;
		i++;
		while (k < s->x)
		{
			s->plateau[j][k] = str[i + k];
			k++;
		}
		j++;
		ft_strdel(&str);
	}
}

void		determine_piece(t_struct *s, char *str)
{
	char *tmp;
	
	get_next_line(0, &str);
	tmp = str;
	while (!(ft_isdigit(*str)))
		str++;
	s->yp = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	s->xp = ft_atoi(str);
	ft_strdel(&tmp);
	s->piece = (char**)ft_memalloc(sizeof(char*) * (s->yp + 1));
	s->i = 0;
	while (s->i < s->yp + 1)
		s->piece[s->i++] = (char*)ft_memalloc(sizeof(char) * (s->xp + 1));
	s->j = 0;
	while (s->j < s->yp)
	{
		get_next_line(0, &str);
		s->i = 0;
		while (s->i < s->xp)
		{
			s->piece[s->j][s->i] = str[s->i];
			s->i++;
		}
		s->j++;
		ft_strdel(&str);
	}
}
