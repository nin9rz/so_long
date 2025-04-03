/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:46 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/03 14:09:23 by jenibaud         ###   ########.fr       */
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
typedef struct s_map
{
	char				**map;
	int					width;
	int					height;
	int					posx;
	int					posy;
}	t_map;

typedef struct s_game
{
	t_map				map;
	void				*mlx;
	void				*mlx_win;
	void				*wall;
	void				*floor;
	void				*left_sprite;
	void				*right_sprite;
	void				*collectible;
	void				*exit;
	void				*box_closed;
	int					mooves;
	unsigned int		collectibles;
	int					is_exit_possible;
}	t_game;

/*------------Parsing------------*/
int		name_ok(char *str);
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
int		get_collectibles_nbr(t_game *game);
int		check_size(t_game *game);
int		check_borders(t_game *game);
int		check_right_and_left(t_game *game);
int		check_top(t_game *game);
int 	check_bottom(t_game *game);

/*------------Images------------*/
int		put_textures_on_screen(t_game *game);
int		load_images(t_game *game);
int		display_wall_texture(t_game *game);
int		display_floor_texture(t_game *game);
int		display_sprite_texture(t_game *game);
int		display_collectible_texture(t_game *game);
int		display_exit_texture(t_game *game);

/*------------free------------*/
void	free_all(t_game	game);

/*------------keys------------*/
int		key_hook(int keycode, t_game *game);

/*------------key hooks------------*/
# define ESC_KEY	65307

# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

/*------------Movements------------*/
int		movement(t_game *game);
void	mov_up(t_game *game);
void	mov_down(t_game *game);
void	mov_left(t_game *game);
void	mov_right(t_game *game);

#endif
