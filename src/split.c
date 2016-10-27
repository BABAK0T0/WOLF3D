/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:06:36 by nrandria          #+#    #+#             */
/*   Updated: 2016/10/26 19:38:49 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clean_up(t_tools *t)
{
	system("killall afplay");
	SDL_FreeSurface(t->icon);
	SDL_DestroyWindow(t->win);
	SDL_Quit();
}

void	raycasting(t_algo *a, t_tools *t, t_coord *c)
{
	init_algo(a, c);
	ray_direction(a);
	dda(a);
	calcul_projection(a);
	color_line(t, a);
}

void	init_tools_coord(t_tools *t, t_coord *c)
{
	init_tools(t);
	init_coord(c);
	menu();
	system("afplay ./sound/sound.mp3 &");
}
