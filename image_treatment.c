/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:55:21 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/01 14:46:30 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_game *game)
{
	int		img_width;
	int		img_height;

	img_width = 64;
	img_height = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &img_width, &img_height);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &img_width, &img_height);
	game->right_sprite = mlx_xpm_file_to_image(game->mlx,
			"textures/right_sprite.xpm", &img_width, &img_height);
	game->left_sprite = mlx_xpm_file_to_image(game->mlx,
			"textures/left_sprite.xpm", &img_width, &img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &img_width, &img_height);
	game->box_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/box_closed.xpm", &img_width, &img_height);
	if (!game->wall || !game->floor || !game->right_sprite || !game->left_sprite
		|| !game->collectible || !game->exit || !game->box_closed)
		return (0);
	return (1);
}

int	put_textures_on_screen(t_game *game)
{
	display_wall_texture(game);
	display_floor_texture(game);
	display_sprite_texture(game);
	display_collectible_texture(game);
	display_exit_texture(game);
	return (1);
}
