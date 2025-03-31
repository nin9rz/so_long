/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:53:36 by jenibaud          #+#    #+#             */
/*   Updated: 2025/03/31 18:36:44 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	name_ok(char *str)
{
	char	*rep;

	if (str == NULL)
		return (0);
	rep = ft_strnstr(str, ".ber", ft_strlen(str));
	if (!rep)
	{
		ft_printf("Error : wrong file format, try 'file_name.ber'\n");
		return (0);
	}
	return (1);
}// ajouter !len < 5

void	free_map(char **map)
{
	int	i;

	i = 0;
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
	ft_printf("Total movement count : %d\n", game->mooves);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_game	game;

	game.mooves = 0;
	if (!name_ok(argv[1]))
		return (0);
	ft_bzero(&game, sizeof(t_game));
	if (!parse(argv[1], &game))
	{
		free_map(game.map.map);
		return (0);
	}
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx,
			((game.map.width -1) * 64), (game.map.height * 64), "so_short");
	load_images(&game);
	put_textures_on_screen(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 1L << 0, close_window, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	free_all(game);
	return (0);
}

void	free_all(t_game	game)
{
	mlx_destroy_image(game.mlx, game.wall);
	mlx_destroy_image(game.mlx, game.floor);
	mlx_destroy_image(game.mlx, game.right_sprite);
	mlx_destroy_image(game.mlx, game.left_sprite);
	mlx_destroy_image(game.mlx, game.collectible);
	mlx_destroy_image(game.mlx, game.exit);
	mlx_destroy_image(game.mlx, game.box_closed);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	free_map(game.map.map);
}
