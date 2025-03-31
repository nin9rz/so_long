/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:50:13 by jenibaud          #+#    #+#             */
/*   Updated: 2025/03/31 16:56:40 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_wall_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[j] != NULL)
	{
		while (game->map.map[j][i] != '\n')
		{
			if (game->map.map[j][i] == '1')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->wall, (i * 64), (j * 64));
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	display_floor_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[j] != NULL)
	{
		while (game->map.map[j][i] != '\n')
		{
			if (game->map.map[j][i] == '0')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->floor, (i * 64), (j * 64));
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	display_sprite_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[j] != NULL)
	{
		while (game->map.map[j][i] != '\n')
		{
			if (game->map.map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->right_sprite, (i * 64), (j * 64));
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	display_collectible_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[j] != NULL)
	{
		while (game->map.map[j][i] != '\n')
		{
			if (game->map.map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->collectible, (i * 64), (j * 64));
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	display_exit_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[j] != NULL)
	{
		while (game->map.map[j][i] != '\n')
		{
			if (game->map.map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->exit, (i * 64), (j * 64));
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
