/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:42:42 by cgodonoa          #+#    #+#             */
/*   Updated: 2017/02/11 13:42:45 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			create_oneline(t_list *head_list, char **line)
{
	t_list	*next;
	t_list_extend	*ptr = (t_list_extend *)head_list;
	int		i;
	int		j;

	//i = ((t_list_extend*)head_list)->nbr_of_obj;
	*line = (char*)malloc((sizeof(char) * ((t_list_extend *)head_list)->nbr_of_obj) + 1);
	//*line = (char*)malloc(sizeof(char) * 15);
	if (!*line)
		return (-1);
	while (head_list)
	{
		next = head_list->ptr_to_next;
		j = 0;
		while (j < head_list->length)
		{
			*(*line + j) = head_list->str[j];
			j++;
		}
		free(head_list);
		head_list = next;
	}
	return (1);
}

int			add_char_onlist(t_list **head, t_list **obj, char c)
{
	if (!*head)
	{
		if (!(*head = (t_list*)malloc(sizeof(t_list_extend))))
			return (-1);
		(*(t_list_extend**)head)->nbr_of_obj = 0;
		(*(t_list_extend**)head)->length = 0;
		(*(t_list_extend**)head)->ptr_to_next = NULL;
		*obj = *head;
	}
	if ((*obj)->length == 10)
	{
		if (!((*obj)->ptr_to_next = (t_list*)malloc(sizeof(t_list))))
			return (-1);
		((*obj)->ptr_to_next)->length = 0;
		((*obj)->ptr_to_next)->ptr_to_next = NULL;
		*obj = ((*obj)->ptr_to_next);
		return (add_char_onlist(head, obj, c));
	}
	(*(t_list_extend**)head)->nbr_of_obj++;
	(*obj)->str[(*obj)->length] = c;
	(*obj)->length++;
	return (1);
}

void		delete_list(t_list **head_list)
{
	t_list	*ptr_to_next;

	while (*head_list)
	{
		ptr_to_next = (*head_list)->ptr_to_next;
		free(*head_list);
		*head_list = ptr_to_next;
	}
	*head_list = NULL;
}

int			get_next_line(int const fd, char **line)
{
	t_list	*head_list;
	t_list	*current_obj;
	char	buff[1];
	int		length;

	buff[0] = '\0';
	head_list = NULL;
	current_obj = NULL;
	while (((length = read(fd, buff, 1)) > 0 ) && buff[0] != '\n')
		if (!add_char_onlist(&head_list, &current_obj, buff[0]))
		{
			delete_list(&head_list);
			return (-1);
		}


	if (length == -1)
	{
		delete_list(&head_list);
		return (-1);
	}
	int i = 0;
	i = ((t_list_extend*)head_list)->nbr_of_obj;
	if (head_list == NULL)
		return (0);
	return (create_oneline(head_list, line));
}
