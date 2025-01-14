/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:53:36 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/14 11:08:24 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	name_ok(char *str)
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
}// ajouter !len < 5

int	main(int argc, char **argv)
{
	(void)argc;
	void	*mlx;
	void	*mlx_win;
	t_game	game;
	
	if (!name_ok(argv[1]))
		return (0);
	ft_bzero(&game, sizeof(t_game));
	if (!parse(argv[1], &game))
		return (0);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
