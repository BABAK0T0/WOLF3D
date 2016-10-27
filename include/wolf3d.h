/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:42:44 by nrandria          #+#    #+#             */
/*   Updated: 2016/10/25 14:31:11 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <SDL2/SDL.h>

# define W 800
# define H 600
# define MAPW 22
# define MAPH 22

typedef struct		s_tools
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Surface		*icon;
	SDL_Event		event;
}					t_tools;

typedef struct		s_coord
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			rush;
	double			rot_rush;
}					t_coord;

typedef struct		s_algo
{
	double			cam_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_s;
	int				draw_e;
	double			old_dir_x;
	double			old_plane_x;
	int				x;
	int				loop;
}					t_algo;

void				color_line(t_tools *t, t_algo *a);
void				menu(void);
void				init_algo(t_algo *a, t_coord *c);
void				init_tools(t_tools *t);
void				init_coord(t_coord *c);
void				calcul_projection(t_algo *a);
void				dda(t_algo *a);
void				ray_direction(t_algo *a);
void				sdlk_up(t_coord *c);
void				sdlk_down(t_coord *c);
void				sdlk_right(t_algo *a, t_coord *c);
void				sdlk_left(t_algo *a, t_coord *c);
void				event(t_algo *a, t_coord *c, t_tools *t);
void				init_tools_coord(t_tools *t, t_coord *c);
void				raycasting(t_algo *a, t_tools *t, t_coord *c);
void				clean_up(t_tools *t);
int					worldmap(int map_x, int map_y);

#endif
