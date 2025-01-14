/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:35:42 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/14 14:37:19 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(char *file, t_game *game)
{
	printf("coucou\n");
	if (!fill_map(file, game))
		return (0);
	if (!is_map_rectangular(game))
		return (0);
	return (1);
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
			ft_printf("Error : map not rectangular.");
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
		ft_printf("Error : map file does not exist");
		return (0);
	}
	return (1);
}
