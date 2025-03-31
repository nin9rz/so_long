/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:55:15 by jenibaud          #+#    #+#             */
/*   Updated: 2025/03/31 17:05:51 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		check_errors(1);
		return (0);
	}
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	fill_map(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;
	int		nbr_lines;

	nbr_lines = count_lines(file);
	game->map.map = malloc((nbr_lines + 1) * sizeof(char *));
	i = 0;
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
	{
		ft_printf("Error : empty map file.\n");
		return (0);
	}
	game->map.width = ft_strlen(temp);
	while (i < nbr_lines)
	{
		game->map.map[i++] = temp;
		temp = get_next_line(fd);
	}
	close(fd);
	game->map.map[i] = NULL;
	game->map.height = nbr_lines;
	return (1);
}
