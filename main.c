/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:53:36 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/07 16:38:25 by jenibaud         ###   ########.fr       */
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
		return (0);
	return (1);
}	

int	main(int argc, char **argv)
{
	(void)argc;
	void	*mlx;
	void	*mlx_win;

	if (!name_ok(argv[1]))
	{
		ft_putstr("Error : wrong file format, try 'file_name.ber'");
		return (0);
	}

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
