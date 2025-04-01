/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:36:37 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/01 14:18:41 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_up(t_game *game)
{
	if (game->map.map[game->map.posy - 1][game->map.posx] == 'E'
		&& game->is_exit_possible == 1)
	{
		mlx_loop_end(game->mlx);
	}
	if (game->map.map[game->map.posy - 1][game->map.posx] != '1'
		&& game->map.map[game->map.posy - 1][game->map.posx] != 'E')
	{
		if (game->map.map[game->map.posy - 1][game->map.posx] == 'C')
			game->collectibles--;
		if (game->collectibles == 0)
		{
			game->is_exit_possible = 1;
		}
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy - 1][game->map.posx] = 'P';
		game->map.posy = game->map.posy - 1;
		game->mooves++;
		ft_printf("Total movement count : %d\n", game->mooves);
		put_textures_on_screen(game);
	}
}

void	mov_down(t_game *game)
{
	if (game->map.map[game->map.posy + 1][game->map.posx] == 'E'
		&& game->is_exit_possible == 1)
	{
		mlx_loop_end(game->mlx);
	}
	if (game->map.map[game->map.posy + 1][game->map.posx] != '1'
		&& game->map.map[game->map.posy + 1][game->map.posx] != 'E')
	{
		if (game->map.map[game->map.posy + 1][game->map.posx] == 'C')
			game->collectibles--;
		if (game->collectibles == 0)
		{
			game->is_exit_possible = 1;
		}
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy + 1][game->map.posx] = 'P';
		game->map.posy = game->map.posy + 1;
		game->mooves++;
		ft_printf("Total movement count : %d\n", game->mooves);
		put_textures_on_screen(game);
	}
}

void	mov_left(t_game *game)
{
	if (game->map.map[game->map.posy][game->map.posx - 1] == 'E'
		&& game->is_exit_possible == 1)
	{
		mlx_loop_end(game->mlx);
	}
	if (game->map.map[game->map.posy][game->map.posx - 1] != '1'
		&& game->map.map[game->map.posy][game->map.posx - 1] != 'E')
	{
		if (game->map.map[game->map.posy][game->map.posx - 1] == 'C')
			game->collectibles--;
		if (game->collectibles == 0)
		{
			game->is_exit_possible = 1;
		}
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy][game->map.posx - 1] = 'P';
		game->map.posx = game->map.posx - 1;
		game->mooves++;
		ft_printf("Total movement count : %d\n", game->mooves);
		put_textures_on_screen(game);
	}
}

void	mov_right(t_game *game)
{
	if (game->map.map[game->map.posy][game->map.posx + 1] == 'E'
		&& game->is_exit_possible == 1)
	{
		mlx_loop_end(game->mlx);
	}
	if (game->map.map[game->map.posy][game->map.posx + 1] != '1'
		&& game->map.map[game->map.posy][game->map.posx + 1] != 'E')
	{
		if (game->map.map[game->map.posy][game->map.posx + 1] == 'C')
			game->collectibles--;
		if (game->collectibles == 0)
		{
			game->is_exit_possible = 1;
		}
		game->map.map[game->map.posy][game->map.posx] = '0';
		game->map.map[game->map.posy][game->map.posx + 1] = 'P';
		game->map.posx = game->map.posx + 1;
		game->mooves++;
		ft_printf("Total movement count : %d\n", game->mooves);
		put_textures_on_screen(game);
	}
}
