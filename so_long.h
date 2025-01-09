/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:46 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/09 14:49:03 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"
# include "src/gnl/get_next_line.h"

/*------------Parsing------------*/
int		check_errors(char **argv);

/*------------Structures------------*/
typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map	*map;
}	t_game;


#endif
