/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:53:36 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/07 13:57:02 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(game->mlx);
		return (0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		mov_up(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		mov_down(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		mov_left(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		mov_right(game);
	return (1);
}

static void	game_start(t_game *game)
{
	put_textures_on_screen(game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, mlx_loop_end, game->mlx);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	game.mooves = 0;
	if (!name_ok(argv[1]))
		return (1);
	ft_bzero(&game, sizeof(t_game));
	if (!parse(argv[1], &game))
	{
		free_map(game.map.map);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		free_map(game.map.map);
		return (1);
	}
	game.mlx_win = mlx_new_window(game.mlx,
		((game.map.width) * 64), (game.map.height * 64), "so_short");
	if (game.mlx_win && load_images(&game))
		game_start(&game);
	free_all(game);
	return (0);
}

void	free_all(t_game	game)
{
	if (game.mlx_win)
		mlx_destroy_window(game.mlx, game.mlx_win);
	if (game.wall)
		mlx_destroy_image(game.mlx, game.wall);
	if (game.floor)
		mlx_destroy_image(game.mlx, game.floor);
	if (game.right_sprite)
		mlx_destroy_image(game.mlx, game.right_sprite);
	if (game.left_sprite)
		mlx_destroy_image(game.mlx, game.left_sprite);
	if (game.collectible)
		mlx_destroy_image(game.mlx, game.collectible);
	if (game.exit)
		mlx_destroy_image(game.mlx, game.exit);
	if (game.box_closed)
		mlx_destroy_image(game.mlx, game.box_closed);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	free_map(game.map.map);
}
