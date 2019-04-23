/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursion.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 17:03:13 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/15 17:03:14 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

t_folder	*ft_folder_origin(char *name, t_folder *prev, int i)
{
	t_folder	*new_link;
	struct stat	buf;

	new_link = (t_folder*)malloc(sizeof(t_folder));
	lstat(name, &buf);
	new_link->name = ft_strdup(name);
	new_link->prev = prev;
	new_link->last_mod = buf.st_mtime;
	new_link->next = NULL;
	new_link->index = i;
	return (new_link);
}

void		ft_folder_append(t_folder *head, char *name, int i)
{
	while (head->next != NULL)
		head = head->next;
	head->next = ft_folder_origin(name, head, i);
}

void		ft_recursive(t_folder *head_folder, char *flags, int flag, int argc)
{
	if (head_folder != NULL && flag == 1 && ft_strchr(flags, 't'))
		head_folder = ft_time_subfolders(head_folder);
	if (flag == 1 && ft_strchr(flags, 'r') && ft_strchr(flags, 'R')
	&& head_folder != NULL)
	{
		while (head_folder->next != NULL)
			head_folder = head_folder->next;
		while (flag == 1 && ft_strchr(flags, 'R') && head_folder != NULL)
		{
			ft_ls(head_folder->name, flags, flag, argc);
			head_folder = head_folder->prev;
		}
	}
	else
	{
		while (flag == 1 && ft_strchr(flags, 'R') && head_folder != NULL)
		{
			ft_ls(head_folder->name, flags, flag, argc);
			head_folder = head_folder->next;
		}
	}
}
