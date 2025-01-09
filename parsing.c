/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:35:42 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/09 14:56:37 by jenibaud         ###   ########.fr       */
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
		ft_printf("Error : wrong file format, try 'file_name.ber'");
		return (0);
	}
	return (1);
}

int	check_errors(char **argv)
{
	if (!name_ok(argv[1]))
		return (0);
	return (1);
}
