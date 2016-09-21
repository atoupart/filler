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

void			make_filler(t_struct *s, int k, int i)
{
	char *str;

	str = NULL; 
	determine_plateau(s);
	determine_piece(s,  str);
	determine_y1_x1(s, k, i);
	if (search(s, s->y1, s->x1) == 0)
	{
		if (parcour(s, k) == 0)
			print_piece(s);
	}
}

int				main(void)
{
	int			i;
	int			k;
	char		*str;
	t_struct	s;
	int ret;

	ft_bzero(&s, sizeof(t_struct));
	str = NULL;
	i = -1;
	k = 1;
	while (42)
	{
		i++;
		k *= -1;
		if (s.player == 0 || s.plateau == NULL)
			init_player_plateau(&s);
		else
		{
			ret = get_next_line(0, &str);
			if (ret == 0)
			{
				ft_strdel(&str);
				return (0);
			}
			else
				ft_putstr_fd("777>", 2);ft_putstr_color(str);
			ft_strdel(&str);
		}
		make_filler(&s, k, i);
		
	}
	return (0);
}
