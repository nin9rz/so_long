/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:26:37 by jenibaud          #+#    #+#             */
/*   Updated: 2025/01/10 12:43:45 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}				t_list_gnl;

char		*get_next_line(int fd);
int			found_newline(t_list_gnl *stash);
t_list_gnl	*ft_lst_get_last(t_list_gnl *stash);
void		read_and_stash(int fd, t_list_gnl **stash);
void		add_to_stash(t_list_gnl **stash, char *buf, int readed);
void		extract_line(t_list_gnl *stash, char **line);
void		generate_line(char **line, t_list_gnl *stash);
void		clean_stash(t_list_gnl **stash);
int			ft_strlen_gnl(const char *str);
void		free_stash(t_list_gnl *stash);
#endif
