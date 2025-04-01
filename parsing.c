/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:35:42 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/01 17:09:59 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(char *file, t_game *game)
{
	if (!fill_map(file, game))
		return (0);
	if (!check_size(game))
		return (0);
	if (!is_map_rectangular(game))
		return (0);
	if (!get_player_position(game))
		return (0);
	get_collectibles_nbr(game);
	if (!get_exit(game))
		return (0);
	if (!flood_fill(game->map))
		return (0);
	return (1);
}

int	get_player_position(t_game *game)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (game->map.map[j])
	{
		while (game->map.map[j][i] != 0)
		{
			if (game->map.map[j][i] == 'P')
			{
				game->map.posy = j;
				game->map.posx = i;
				res = 1;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (res);
}

int	get_exit(t_game *game)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (game->map.map[j])
	{
		while (game->map.map[j][i] != 0)
		{
			if (game->map.map[j][i] == 'E')
			{
				res = 1;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (res);
}

int	is_map_rectangular(t_game *game)
{
	char	*temp;
	int		i;
	int		len;

	i = 0;
	temp = game->map.map[i];
	while (temp != NULL)
	{
		len = ft_strlen(temp);
		if (game->map.width != len)
		{
			ft_printf("\nError : map not rectangular.\n");
			return (0);
		}
		i++;
		temp = game->map.map[i];
	}
	return (1);
}

int	check_errors(int error)
{
	if (error == 1)
	{
		ft_printf("Error : map file does not exist\n");
		return (0);
	}
	return (1);
}
