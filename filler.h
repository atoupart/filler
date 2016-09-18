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

#define pte ft_putendl_fd
#define pts ft_putstr_fd
#define ptn ft_putnbr_fd
#define ptcn ft_putchar_fd('\n', 2)
#define p fprintf

void		ft_putstr_color(char *str);



typedef	struct 		s_struct
{
	int				player;				//determine p1 ou p2 -> O ou X
	char			l_player;			// lettre du joueur
	char			l_opponent;			//	lettre 1 de l'adversaire
	char			l_opponent2;			//	lettre 2 de l'adversaire

	char			**plateau;			// tableau double entree qui stocke le plateau
	char			**piece;			// tbleau double entree qui stocke la piece 
	int				y;					//ordonné max plateau
	int				x;					//abscisse max plateau
	int				yp;					//ordonne total piece
	int				xp;					//abscisse total piece
	int				y1;				//ordonné point player plateau
	int				x1;				//abscisse point player plateau
	int				yy1;				//ordonné point player plateau dans find2
	int				xx1;				//abscisse point player plateau dans find2
	int				y2;				//ordonné point opponent plateau
	int				x2;				//abscisse point opponent plateau
	int    			ap;				//abscisse point piece mouvant  general
	int    			app;				//abscisse point piece mouvant dans search point 

	int 			op;				//ordonne point piece mouvant dans search point
	int    			ap2;			//abscisse point piece mouvant dans la verif de piece
	int 			op2;			//ordonne point piece mouveant dans la verif de piece
	int				py;				//ordonne point piece initial
	int				px;				//abscisse point piece initial
	int				pyy;				//ordonne point piece initial dans reorientate_piece
	int				pxx;				//abscisse point piece initial dans reorientate piece
	int				nb_star;		//nombre de * dans la ligne donner
	int				nb;				//nombre qui va verifier les *
	int				ok_line;		// determine si tout se passe bien sur les verification de posage de piece
	int				ok_height;		// determiner si tout se passe bien par colonne	
	int				ok_star;			// determine si il y a bien une etoile chevauché 
	int				height;			//hauteur de la piece reel
	int				diff;			//determine la difference entre l'absiesse de chaque ligne
	int				ecart;			//determine lecart entre l'abscisse de chaque ligne de search point

	int diff_h;						// difference hauteur orientation piece
	int diff_l;						// difference largeur orientation piece
	int				i;				// index utile
	int				j;				// index utile	
	int 			result;			//pour find 1
	int 			result2;		//pour find 2
	int 			res_o;		//pour opponent
	int 			res_p;		//pour player


	int 			res_orient;		//pour orientation piece 1
	int 			res_orient2;		//pour orientation piece 2

	int				ver;
	int				nb_touch_opponent;
	int				nb_test_around;
	int				nb_parcour_point_hg;
	int				nb_parcour_point_bd;
	int				nb_parcour_point_hd;

}					t_struct;

/*
**				filler.c
*/

int					main();


/*
**				init_and_determine.c
*/

void				init_player_plateau(t_struct *s, char *str);
void				determine_plateau(t_struct *s, char *str);
void				determine_piece(t_struct *s, char *str);

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

int					verif_line_piece(t_struct *s, int j, int y1, int x1);
int					verif_piece_posable(t_struct *s, int y1, int x1);
int					search_position(t_struct *s, int y1, int x1);

/*
**				search_position2.c
*/

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

int					calcul_o(t_struct *s, int y2, int x2);
int					calcul_p(t_struct *s, int y1, int x1);
int					find_point_player_hg(t_struct *s);
int					find_point_player_hd(t_struct *s);
int					find_point_player_bg(t_struct *s);
int					find_point_player_bd(t_struct *s);
int					find_point_opponent_bd(t_struct *s);
int					find_point_opponent_hg(t_struct *s);
int					look_around(t_struct *s, int y1, int x1);
int					touch_around(t_struct *s, int y1, int x1);


/*
**				orientate_piece.c
*/

int					calcul2(int y1, int x1, int y2, int x2);
int					find_opdown(t_struct *s);
int 				find_apleft(t_struct *s);
// int					find_apright(t_struct *s);
void				orientate_piece(t_struct *s);

/*
**				search.c
*/

int					search(t_struct *s, int y1, int x1);

/*
**				parcour_point.c
*/

int					parcour(t_struct *s, int k);
int					parcour_point_hg(t_struct *s);
int					parcour_point_hd(t_struct *s);
int					parcour_point_bd(t_struct *s);
int					test_around(t_struct *s);
int 				touch_opponent(t_struct *s);

/*
**				diagonal_point.c
*/

int				find_direction(t_struct *s, int l);
void			indicate_direction(t_struct *s, int l, int k);
void			indicate_direction2(t_struct *s, int l, int k);





#endif
