/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:42:25 by cgodonoa          #+#    #+#             */
/*   Updated: 2017/02/11 13:42:27 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 10

typedef struct		s_list
{
	char			str[10];
	short			length;
	struct s_list	*ptr_to_next;
}					t_list;

typedef struct		s_list_extend
{
	char			str[10];
	short			length;
	struct s_list	*ptr_to_next;
	int				nbr_of_obj;
}					t_list_extend;

int					get_next_line(int const fd, char **line);
int					create_oneline(t_list *head_list, char **line);
int					add_char_onlist(t_list **head, t_list **obj, char c);
void				delete_list(t_list **head_list);
#endif
