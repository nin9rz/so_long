/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:15:06 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/01 17:11:39 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_map OGmap)
{
	int		x;
	int		y;
	int		i;
	int		error;
	char	**map;

	x = OGmap.posx;
	y = OGmap.posy;
	error = 1;
	i = 0;
	map = map_cpy(OGmap);
	flood(map, x, y);
	error = is_map_solvable(map);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (error);
}

char	**map_cpy(t_map OGmap)
{
	char	**map;
	int		i;

	map = malloc((OGmap.height + 1) * sizeof(char *));
	i = 0;
	while (OGmap.map[i])
	{
		map[i] = ft_strdup(OGmap.map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	flood(char **map, int x, int y)
{
	if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	map[x][y] = '1';
	if (map[x -1][y] != '1')
		flood(map, x -1, y);
	if (map[x][y +1] != '1')
		flood(map, x, y +1);
	if (map[x +1][y] != '1')
		flood(map, x +1, y);
	if (map[x][y -1] != '1')
		flood(map, x, y -1);
}

int	is_map_solvable(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		while (map[j][i] != 0)
		{
			if (map[j][i] != '0' && map [j][i] != '1')
			{
				ft_printf("Error : unsolvable map.\n");
				return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_size(t_game *game)
{
	if (game->map.width > 30 || game->map.height > 16)
	{
		ft_printf("Error : map too big\n");
		return (0);
	}
	return (1);
}
