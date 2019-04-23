/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:57:20 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:57:21 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_initialize_null(t_file **head, t_folder **head_folder)
{
	*head = NULL;
	*head_folder = NULL;
}

void	ft_close_dir(DIR *dir)
{
	if (dir != NULL)
		closedir(dir);
}

void	ft_initialize_ls(DIR **dir, t_file **head, t_folder **folder, char *p)
{
	*dir = opendir(p);
	ft_initialize_null(head, folder);
	ft_print_path(NULL, 0, 0, NULL);
}

void	ft_ls_error(char *path, int flag, int argc, char *flags)
{
	ft_print_path(path, flag, argc, flags);
	ft_putstr_fd("ft_ls: ", 2);
	ft_print_name_err(path);
	perror("");
}

void	ft_ls(char *path, char *flags, int flag, int argc)
{
	DIR				*dir;
	struct dirent	*sd;
	t_file			*head;
	t_folder		*head_folder;
	char			pathname[1025];

	ft_initialize_ls(&dir, &head, &head_folder, path);
	if (dir == NULL)
	{
		ft_ls_error(path, flag, argc, flags);
		return ;
	}
	while ((sd = readdir(dir)) != NULL)
	{
		ft_print_path(path, flag, argc, flags);
		if (ft_validate(sd, flag, flags) || ft_validate2(sd, flag, flags))
		{
			ft_pathname(pathname, path, sd->d_name);
			ft_file_list_launcher(&head, pathname, flags, flag);
		}
		if (ft_validate(sd, flag, flags))
			ft_folder_list_launcher(&head_folder, pathname, flags, flag);
	}
	ft_ls_file_launcher(&head, flags, flag, dir);
	ft_ls_directories_launcher(&head_folder, flags, flag, argc);
}
