/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:00:07 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/22 20:00:10 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

int					get_next_line(int const fd, char **line);


typedef	struct		s_struct
{
	int				player;
	char			l_player;
	char			l_opponent;
	char			l_opponent2;
	char			**plateau;
	char			**piece;
	int				xinit;
	int				yinit;
	int				yrim;
	int				xrim;
	int				y;
	int				x;
	int				yp;
	int				xp;
	int				y1;
	int				x1;
	int				yy1;
	int				xx1;
	int				y2;
	int				x2;
	int				ap;
	int				app;
	int				op;
	int				ap2;
	int				op2;
	int				py;
	int				px;
	int				pyy;
	int				pxx;
	int				nb_star;
	int				nb;
	int				ok_line;
	int				ok_height;
	int				ok_star;
	int				height;
	int				diff;
	int				ecart;
	int				diff_h;
	int				diff_l;
	int				i;
	int				j;
	int				result;
	int				result2;
	int				res_o;
	int				res_p;
	int				res_orient;
	int				res_orient2;
	int				rim;
	int				ver;
	int				ppx;
	int				ppy;
	int				xx;
	int				yy;
	int				ii;

}					t_struct;

/*
**				color_filler.c
*/

void				ft_putstr_color(char *str);

/*
**				filler.c
*/

void				make_filler(t_struct *s, int k, int i);
int					main(void);

/*
**				init_and_determine.c
*/

void				init_player_plateau(t_struct *s);
void				determine_plateau(t_struct *s);
void				determine_piece(t_struct *s, char *str);

/*
**				determine_y1_x1.c
*/

void				determine_rim(t_struct *s);
void				follow_rim(t_struct *s);
int					verif_rim(t_struct *s);
void				determine_y1_x1(t_struct *s, int k, int i);

/*
**				recursive_point.c
*/

void				recursive_find_best_points(t_struct *s);
int					precise_player(t_struct *s);
int					precise_player_diag(t_struct *s);
int					precise_opponent(t_struct *s);
int					precise_opponent_diag(t_struct *s);

/*
**				search_position.c
*/

int					inside_verif_ligne_piece(t_struct *s, int y1, int x1);
int					inside_search_position(t_struct *s, int y1, int x1);
int					verif_line_piece(t_struct *s, int j, int y1, int x1);
int					verif_piece_posable(t_struct *s, int y1, int x1);
int					search_position(t_struct *s, int y1, int x1);

/*
**				search_position2.c
*/

int					inside_search_position1(t_struct *s, int nb_star, int pxx);
int					inside_search_position2(t_struct *s, int y1, int x1);
int					verif_line_piece2(t_struct *s, int j, int y1, int x1);
int					verif_piece_posable2(t_struct *s, int y1, int x1);
int					search_position2(t_struct *s, int y1, int x1);

/*
**				fonctions_tool.c
*/

void				print_piece(t_struct *s);
int					nb_star_line(t_struct *s, int py);
int					height_piece(t_struct *s);
int					find_first_star(t_struct *s, int j);
int					find_last_star(t_struct *s, int opj);

/*
**				fonctions_tool2.c
*/

int					find_point_player_hg(t_struct *s);
int					find_point_player_bd(t_struct *s);
int					find_point_opponent_bd(t_struct *s);
int					find_point_opponent_hg(t_struct *s);
int					look_around(t_struct *s, int y1, int x1);

/*
**				orientate_piece.c
*/

int					calcul2(int y1, int x1, int y2, int x2);
int					find_opdown(t_struct *s);
int					find_apleft(t_struct *s);
void				orientate_piece(t_struct *s);

/*
**				search.c
*/

int					search(t_struct *s, int y1, int x1);
int					calcul_o(t_struct *s, int y2, int x2);
int					calcul_p(t_struct *s, int y1, int x1);
int					touch_around(t_struct *s, int y1, int x1);
int					touch_around_2(t_struct *s, int y1, int x1);

/*
**				parcour_point.c
*/

int					parcour(t_struct *s, int k);
int					parcour_point_hg(t_struct *s);
int					parcour_point_hd(t_struct *s);
int					parcour_point_bd(t_struct *s);

/*
**				tool_parcour_search.c
*/

int					touch_op2(t_struct *s, int k, int j, int i);
int					test_ar_2(t_struct *s, int k, int j, int i);
int					test_around(t_struct *s);
int					touch_opponent(t_struct *s);
int					inside_verif_ligne_piece2(t_struct *s, int y1, int x1);

/*
**				diagonal_point.c
*/

int					find_direction(t_struct *s, int l);
void				indicate_direction(t_struct *s, int l, int k);
void				indicate_direction2(t_struct *s, int l, int k);

#endif
