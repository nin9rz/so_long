/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:36:37 by jenibaud          #+#    #+#             */
/*   Updated: 2025/03/31 18:37:05 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_up(t_game *game)
{
	if (game->map.map[game->map.posy - 1][game->map.posx] != '1')
	{
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy - 1][game->map.posx] = 'P';
		game->map.posy = game->map.posy - 1;
		game->mooves++;
		put_textures_on_screen(game);
	}
}

void	mov_down(t_game *game)
{
	if (game->map.map[game->map.posy + 1][game->map.posx] != '1')
	{
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy + 1][game->map.posx] = 'P';
		game->map.posy = game->map.posy + 1;
		game->mooves++;
		put_textures_on_screen(game);
	}
}

void	mov_left(t_game *game)
{
	if (game->map.map[game->map.posy][game->map.posx - 1] != '1')
	{
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy][game->map.posx - 1] = 'P';
		game->map.posx = game->map.posx - 1;
		game->mooves++;
		put_textures_on_screen(game);
	}
}

void	mov_right(t_game *game)
{
	if (game->map.map[game->map.posy][game->map.posx + 1] != '1')
	{
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy][game->map.posx + 1] = 'P';
		game->map.posx = game->map.posx + 1;
		game->mooves++;
		put_textures_on_screen(game);
	}
}
