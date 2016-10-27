/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:45:32 by nrandria          #+#    #+#             */
/*   Updated: 2016/10/25 14:26:44 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				init_coord(t_coord *c)
{
	c->pos_x = 19;
	c->pos_y = 11;
	c->dir_x = -1;
	c->dir_y = 0;
	c->plane_x = 0;
	c->plane_y = 0.60;
	c->rush = 0.15;
	c->rot_rush = 0.1;
}

void				init_tools(t_tools *t)
{
	SDL_Init(SDL_INIT_VIDEO);
	t->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_OPENGL);
	t->renderer = SDL_CreateRenderer(t->win, -1, SDL_RENDERER_ACCELERATED);
	t->icon = SDL_LoadBMP("../img/the-games-logo.bmp");
	SDL_SetWindowIcon(t->win, t->icon);
}

void				init_algo(t_algo *a, t_coord *c)
{
	a->cam_x = 2 * a->x / (double)W - 1;
	a->ray_pos_x = c->pos_x;
	a->ray_pos_y = c->pos_y;
	a->ray_dir_x = c->dir_x + c->plane_x * a->cam_x;
	a->ray_dir_y = c->dir_y + c->plane_y * a->cam_x;
	a->map_x = (int)a->ray_pos_x;
	a->map_y = (int)a->ray_pos_y;
	a->delta_dist_x = sqrt(1 + (a->ray_dir_y * a->ray_dir_y)
		/ (a->ray_dir_x * a->ray_dir_x));
	a->delta_dist_y = sqrt(1 + (a->ray_dir_x * a->ray_dir_x)
		/ (a->ray_dir_y * a->ray_dir_y));
	a->hit = 0;
}

void				menu(void)
{
	ft_putendl("------------------------");
	ft_putendl("|        M E N U       |");
	ft_putendl("|----------------------|");
	ft_putendl("| UP : Move forward    |");
	ft_putendl("| DOWN : Move backward |");
	ft_putendl("| LEFT : Rotate left   |");
	ft_putendl("| RIGHT : Rotate right |");
	ft_putendl("| R : Reset            |");
	ft_putendl("| ESC : Quit           |");
	ft_putendl("------------------------");
	ft_putendl("|        WOLF_3D       |");
	ft_putendl("------------------------");
}

void				color_line(t_tools *t, t_algo *a)
{
	SDL_SetRenderDrawColor(t->renderer, 70, 178, 157, 255);
	SDL_RenderDrawLine(t->renderer, a->x, 0, a->x, a->draw_s);
	if (a->side == 0 && a->ray_dir_x > 0)
		SDL_SetRenderDrawColor(t->renderer, 222, 91, 73, 255);
	else if (a->side == 0 && a->ray_dir_x < 0)
		SDL_SetRenderDrawColor(t->renderer, 227, 123, 64, 255);
	else if (a->side == 1 && a->ray_dir_y > 0)
		SDL_SetRenderDrawColor(t->renderer, 240, 202, 77, 255);
	else
		SDL_SetRenderDrawColor(t->renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(t->renderer, a->x, a->draw_s, a->x, a->draw_e);
	SDL_SetRenderDrawColor(t->renderer, 50, 77, 92, 255);
	SDL_RenderDrawLine(t->renderer, a->x, a->draw_e, a->x, H);
}
