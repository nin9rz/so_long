/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:46 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/14 13:45:18 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*------------Include libraries------------*/
# include <fcntl.h>
# include <stdlib.h>

/*------------Include local files------------*/
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"
# include "src/gnl/get_next_line.h"

/*------------Structures------------*/
typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

/*------------Parsing------------*/
int		check_errors(int error);
int		fill_map(char *file, t_game *game);
int		count_lines(char *file);
int		is_map_rectangular(t_game *game);
int		parse(char *file, t_game *game);

#endif
