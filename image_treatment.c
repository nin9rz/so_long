/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:55:21 by jenibaud          #+#    #+#             */
/*   Updated: 2025/03/28 16:55:54 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int		img_width;
	int		img_height;

	img_width = 64;
	img_height = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/east.xpm", &img_width, &img_height);
	//ajouter autres textures (mm ligne qu'au-dessus)
}
