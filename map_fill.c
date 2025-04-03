/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:55:15 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/03 18:39:15 by jenibaud         ###   ########.fr       */
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

char	*get_map_line(int fd)
{
	char	*temp;

	if (fd < 0)
		return (NULL);
	temp = get_next_line(fd);
	if (!temp)
		return (temp);
	if (temp[ft_strlen(temp) - 1] == '\n')
		temp[ft_strlen(temp) - 1] = '\0';
	return (temp);
}

int	fill_map(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;
	int		nbr_lines;

	nbr_lines = count_lines(file);
	game->map.map = ft_calloc((nbr_lines + 1), sizeof(char *));
	i = 0;
	fd = open(file, O_RDONLY);
	temp = get_map_line(fd);
	if (!temp)
	{
		ft_printf("Error : empty map file.\n");
		return (0);
	}
	game->map.width = ft_strlen(temp);
	while (i < nbr_lines)
	{
		game->map.map[i++] = temp;
		temp = get_map_line(fd);
	}
	close(fd);
	game->map.map[i] = NULL;
	game->map.height = nbr_lines;
	return (1);
}

int	get_collectibles_nbr(t_game *game)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	j = 0;
	while (game->map.map[j])
	{
		while (game->map.map[j][i] != 0)
		{
			if (game->map.map[j][i] == 'C')
				game->collectibles++;
			i++;
		}
		i = 0;
		j++;
	}
	if (game->collectibles == 0)
		return (0);
	return (1);
}

int	name_ok(char *str)
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
}
