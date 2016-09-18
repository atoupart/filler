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


		if (l == 0 && k == -1)
		{
			find_point_player_hg(&s);
			find_point_opponent_hg(&s);
		}
		if (l == 1 && k == 1)
		{
			find_point_player_bd(&s);
			find_point_opponent_bd(&s);
		}
		if (l == 2 && k == -1)
		{
			find_point_player_hg(&s);
			find_point_opponent_bd(&s);
		}
		if (l == 0 && k == 1)
		{
			find_point_player_hg(&s);
			find_point_opponent_hg(&s);
		}
		if (l == 1 && k == -1)
		{
			find_point_player_hg(&s);
			find_point_opponent_hg(&s);
		}
		if (l == 2 && k == 1)
		{
			find_point_player_bd(&s);
			find_point_opponent_hg(&s);
		}