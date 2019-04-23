/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 17:01:21 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/12 17:01:22 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

t_file	*ft_file_origin(char *name, char *flags, int flag, t_file *prev)
{
	t_file		*new_link;
	struct stat	buf;

	new_link = (t_file*)malloc(sizeof(t_file));
	ft_file_origin_basics(new_link, prev, name);
	if (lstat(name, &buf) == -1)
	{
		new_link->err = 1;
		return (new_link);
	}
	new_link->last_mod = buf.st_mtime;
	if (flag == 0 || ft_strchr(flags, 'l') == NULL)
		return (new_link);
	ft_file_origin_type(new_link);
	if (ft_isdevice(new_link) && new_link->type != 's' && new_link->type != 'p')
		ft_file_origin_device(&buf, new_link);
	new_link->permissions = ft_permissions(name, &buf);
	new_link->hardlinks = buf.st_nlink;
	ft_file_origin_id(&buf, new_link);
	ft_file_origin_date(&buf, new_link);
	new_link->size = buf.st_size;
	new_link->l_flag = 1;
	new_link->blocks = buf.st_blocks;
	return (new_link);
}

void	ft_file_append(t_file *head, char *name, char *flags, int flag)
{
	while (head->next != NULL)
		head = head->next;
	head->next = ft_file_origin(name, flags, flag, head);
}

t_file	*ft_list_files(int *files, char **argv, char *flags, int flag)
{
	int		i;
	t_file	*head;

	i = 0;
	head = NULL;
	while (files[i] > 0)
	{
		if (head == NULL)
			head = ft_file_origin(argv[files[i]], flags, flag, NULL);
		else
			ft_file_append(head, argv[files[i]], flags, flag);
		i++;
	}
	return (head);
}
