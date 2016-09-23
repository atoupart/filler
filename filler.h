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
	int				x2init;
	int				y2init;
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
	int				ret;
	int				ver;
	int				ppx;
	int				ppy;
	int				xx;
	int				yy;
	int				ii;
	int				h;
	int				w;

}					t_struct;


/*
**				tcheck_piece.c
*/

void				tcheck_piece_height(t_struct *s);
void				tcheck_piece_width(t_struct *s);

/*
**				verif_rime.c
*/

int					verif_rim_h(t_struct *s);
int					verif_rim_d(t_struct *s);
int					verif_rim_b(t_struct *s);
int					verif_rim_g(t_struct *s);

/*
**				find_point_player.c
*/

int					find_point_player_hg(t_struct *s);
int					find_point_player_bg(t_struct *s);
int					find_point_player_hd(t_struct *s);
int					find_point_player_bd(t_struct *s);

/*
**				find_point_player2.c
*/

int					find_point_player_gh(t_struct *s);
int					find_point_player_gb(t_struct *s);
int					find_point_player_dh(t_struct *s);
int					find_point_player_db(t_struct *s);

/*
**				find_point_opponent.c
*/

int					find_point_opponent_hg(t_struct *s);
int					find_point_opponent_hd(t_struct *s);
int					find_point_opponent_bg(t_struct *s);
int					find_point_opponent_bd(t_struct *s);

/*
**				carli_style.c
*/


void				carli_style_bd(t_struct *s, int k);
void				carli_style_bg(t_struct *s, int k);
void				carli_style_hd(t_struct *s, int k);
void				carli_style_hg(t_struct *s, int k);

/*
**				color_filler.c
*/

void				ft_putstr_color(char *str);
void				init_player_plateau(t_struct *s);
void				determine_plateau(t_struct *s);
void				determine_piece(t_struct *s, char *str, char *tmp);

/*
**				filler.c
*/

void				free_piece(t_struct *s);
void				free_all(t_struct *s);
void				determine_carli(t_struct *s, int i, int k);
void				make_filler(t_struct *s, int k, int i);
int					main(void);

/*
**				init_and_determine.c
*/

void				init_player_plateau(t_struct *s);
void				determine_plateau(t_struct *s);
void				determine_piece(t_struct *s, char *str, char *tmp);

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
int					look_around(t_struct *s, int y1, int x1);

/*
**				tool_parcour_search.c
*/

int					touch_op2(t_struct *s, int k, int j, int i);
int					test_ar_2(t_struct *s, int k, int j, int i);
int					test_around(t_struct *s);
int					touch_opponent(t_struct *s);
int					inside_verif_ligne_piece2(t_struct *s, int y1, int x1);

#endif
