/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 16:12:26 by nrandria          #+#    #+#             */
/*   Updated: 2016/05/27 16:17:28 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					worldmap(int map_x, int map_y)
{
	static int worldmap[MAPW][MAPH] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	return (worldmap[map_x][map_y]);
}

void				ray_direction(t_algo *a)
{
	if (a->ray_dir_x < 0)
	{
		a->step_x = -1;
		a->side_dist_x = (a->ray_pos_x - a->map_x) * a->delta_dist_x;
	}
	else
	{
		a->step_x = 1;
		a->side_dist_x = (a->map_x + 1.0 - a->ray_pos_x) * a->delta_dist_x;
	}
	if (a->ray_dir_y < 0)
	{
		a->step_y = -1;
		a->side_dist_y = (a->ray_pos_y - a->map_y) * a->delta_dist_y;
	}
	else
	{
		a->step_y = 1;
		a->side_dist_y = (a->map_y + 1.0 - a->ray_pos_y) * a->delta_dist_y;
	}
}

void				dda(t_algo *a)
{
	while (a->hit == 0)
	{
		if (a->side_dist_x < a->side_dist_y)
		{
			a->side_dist_x += a->delta_dist_x;
			a->map_x += a->step_x;
			a->side = 0;
		}
		else
		{
			a->side_dist_y += a->delta_dist_y;
			a->map_y += a->step_y;
			a->side = 1;
		}
		if ((worldmap(a->map_x, a->map_y)) > 0)
			a->hit = 1;
	}
}

void				calcul_projection(t_algo *a)
{
	if (a->side == 0)
	{
		a->perp_wall_dist =
			(a->map_x - a->ray_pos_x + (1 - a->step_x) / 2) / a->ray_dir_x;
	}
	else
	{
		a->perp_wall_dist =
			(a->map_y - a->ray_pos_y + (1 - a->step_y) / 2) / a->ray_dir_y;
	}
	a->line_h = (int)(H / a->perp_wall_dist);
	a->draw_s = -a->line_h / 2 + H / 2;
	if (a->draw_s < 0)
		a->draw_s = 0;
	a->draw_e = a->line_h / 2 + H / 2;
	if (a->draw_e >= H)
		a->draw_e = H - 1;
}

int					main(int ac, char **av)
{
	t_tools			t;
	t_coord			c;
	t_algo			a;

	if (ac == 1 && av[0][0])
	{
		init_tools_coord(&t, &c);
		a.loop = 1;
		while (a.loop)
		{
			event(&a, &c, &t);
			a.x = 0;
			while (a.x < W)
			{
				raycasting(&a, &t, &c);
				a.x++;
			}
			SDL_RenderPresent(t.renderer);
		}
		clean_up(&t);
	}
	else
		ft_putstr_fd("usage: ./wolf3d\n", 2);
	return (0);
}
