/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_launchers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:53:18 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:53:19 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_file_list_launcher(t_file **head, char *path, char *flags, int flag)
{
	if (*head == NULL)
		*head = ft_file_origin(path, flags, flag, NULL);
	else
		ft_file_append(*head, path, flags, flag);
}

void	ft_folder_list_launcher(t_folder **head, char *path, char *f, int flag)
{
	struct stat	buf;

	lstat(path, &buf);
	if (S_ISDIR(buf.st_mode) && flag == 1 && ft_strchr(f, 'R'))
	{
		if (*head == NULL)
			*head = ft_folder_origin(path, NULL, 0);
		else
			ft_folder_append(*head, path, 0);
	}
	ft_bzero(path, 1025);
}

void	ft_ls_file_launcher(t_file **head, char *flags, int flag, DIR *dir)
{
	ft_close_dir(dir);
	ft_sort_files(head, flags, flag);
	ft_display(*head, flags, flag, 1);
	ft_free_files(*head);
}

void	ft_ls_directories_launcher(t_folder **head, char *flags, int f, int a)
{
	ft_sort_folders(head, flags, f);
	ft_recursive(*head, flags, f, a);
	ft_free_folders(*head);
}
