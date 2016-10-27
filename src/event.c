/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:13:30 by nrandria          #+#    #+#             */
/*   Updated: 2016/05/27 16:21:55 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdlk_up(t_coord *c)
{
	if (worldmap(((int)(c->pos_x + c->dir_x * c->rush)), ((int)c->pos_y)) == 0)
		c->pos_x += c->dir_x * c->rush;
	if (worldmap(((int)c->pos_x), ((int)(c->pos_y + c->dir_y * c->rush))) == 0)
		c->pos_y += c->dir_y * c->rush;
}

void	sdlk_down(t_coord *c)
{
	if (worldmap((int)(c->pos_x - c->dir_x * c->rush), (int)(c->pos_y)) == 0)
		c->pos_x -= c->dir_x * c->rush;
	if (worldmap((int)(c->pos_x), (int)(c->pos_y - c->dir_y * c->rush)) == 0)
		c->pos_y -= c->dir_y * c->rush;
}

void	sdlk_right(t_algo *a, t_coord *c)
{
	a->old_dir_x = c->dir_x;
	c->dir_x = c->dir_x * cos(-c->rot_rush) - c->dir_y * sin(-c->rot_rush);
	c->dir_y = a->old_dir_x * sin(-c->rot_rush)
	+ c->dir_y * cos(-c->rot_rush);
	a->old_plane_x = c->plane_x;
	c->plane_x = c->plane_x * cos(-c->rot_rush)
	- c->plane_y * sin(-c->rot_rush);
	c->plane_y = a->old_plane_x * sin(-c->rot_rush)
	+ c->plane_y * cos(-c->rot_rush);
}

void	sdlk_left(t_algo *a, t_coord *c)
{
	a->old_dir_x = c->dir_x;
	c->dir_x = c->dir_x * cos(c->rot_rush) - c->dir_y * sin(c->rot_rush);
	c->dir_y = a->old_dir_x * sin(c->rot_rush) + c->dir_y * cos(c->rot_rush);
	a->old_plane_x = c->plane_x;
	c->plane_x = c->plane_x * cos(c->rot_rush) - c->plane_y
	* sin(c->rot_rush);
	c->plane_y = a->old_plane_x * sin(c->rot_rush) + c->plane_y
	* cos(c->rot_rush);
}

void	event(t_algo *a, t_coord *c, t_tools *t)
{
	while (SDL_PollEvent(&t->event) != 0)
	{
		if (t->event.type == SDL_QUIT)
			a->loop = 0;
		if (t->event.type == SDL_KEYDOWN)
		{
			if (t->event.key.keysym.sym == SDLK_UP)
				sdlk_up(c);
			if (t->event.key.keysym.sym == SDLK_DOWN)
				sdlk_down(c);
			if (t->event.key.keysym.sym == SDLK_RIGHT)
				sdlk_right(a, c);
			if (t->event.key.keysym.sym == SDLK_LEFT)
				sdlk_left(a, c);
			if (t->event.key.keysym.sym == SDLK_ESCAPE)
				a->loop = 0;
			if (t->event.key.keysym.sym == SDLK_r)
				init_coord(c);
		}
	}
}
