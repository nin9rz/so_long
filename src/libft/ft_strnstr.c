/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:17:08 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/07 16:17:49 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*it;

	i = 0;
	if ((!big || !little) && !len)
		return (NULL);
	it = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	while ((*it != '\0') && len != 0)
	{
		i = 0;
		while (it[i] == little[i])
		{
			if (little[i + 1] == '\0' && i < len)
				return (it);
			i++;
		}
		it++;
		len--;
	}
	return (NULL);
}
