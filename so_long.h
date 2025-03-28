/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:46 by jenibaud          #+#    #+#             */
/*   Updated: 2025/03/28 16:55:53 by jenibaud         ###   ########.fr       */
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
	int		posx;
	int		posy;
}	t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	//ajouter autres textures (mm ligne qu'au-dessus)
}	t_game;

/*------------Parsing------------*/
int		check_errors(int error);
int		fill_map(char *file, t_game *game);
int		count_lines(char *file);
int		is_map_rectangular(t_game *game);
int		parse(char *file, t_game *game);
int		flood_fill(t_map OGmap);
int		get_player_position(t_game *game);
int		get_exit(t_game *game);
void	flood(char **map, int x, int y);
char	**map_cpy(t_map OGmap);
int		is_map_solvable(char **map);

/*------------Images------------*/
void	load_images(t_game *game);

/*------------keys------------*/
int		key_hook(int keycode, t_game *game);

/*------------key hooks------------*/
# define	ESC_KEY	65307

#endif
