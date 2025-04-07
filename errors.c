/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:24:35 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/07 13:26:44 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(t_game *game)
{
	if (!check_top(game) || !check_right_and_left(game) || !check_bottom(game))
	{
		printf("Error : borders not ok.\n");
		return (0);
	}
	return (1);
}

int	check_right_and_left(t_game *game)
{
	int	i;
	int	max;

	i = 0;
	max = game->map.width - 1;
	while (game->map.map[i] != NULL)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][max] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_top(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i][j] != '\0')
	{
		if (game->map.map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_bottom(t_game *game)
{
	int	i;
	int	j;

	i = game->map.height - 1;
	j = 0;
	while (game->map.map[i][j] != '\0')
	{
		if (game->map.map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
