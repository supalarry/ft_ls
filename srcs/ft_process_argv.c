/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_process_argv.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 12:42:35 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/11 12:42:36 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_free(int *files, int *directories, t_file *files_head)
{
	if (files != NULL)
		free(files);
	if (directories != NULL)
		free(directories);
	if (files_head != NULL)
		ft_free_files(files_head);
}

int		ft_index(int *directories, int flag, char **flags)
{
	int i;

	i = 0;
	if (directories != NULL && flag == 1 && ft_strchr(*flags, 'r'))
	{
		while (directories[i] > 0)
			i++;
		i--;
	}
	return (i);
}

void	ft_process_directories(char **argv, int argc, char **flags, int flag)
{
	int	*directories;
	int	i;

	directories = ft_argv_directories(argv, argc, flags);
	i = ft_index(directories, flag, flags);
	if (flag == 1 && ft_strchr(*flags, 't'))
		ft_time_directories(argv, directories);
	if (flag == 1 && ft_strchr(*flags, 'r'))
	{
		while (i >= 0)
		{
			ft_ls(argv[directories[i]], *flags, flag, argc);
			i--;
		}
	}
	else
	{
		while (directories[i] > 0)
		{
			ft_ls(argv[directories[i]], *flags, flag, argc);
			i++;
		}
	}
	free(directories);
}

void	ft_process_argv(char **argv, int argc, char **flags, int flag)
{
	int		*files;
	int		*directories;
	t_file	*files_head;
	int		block;

	block = 0;
	ft_error_argv(argv, argc, *flags);
	files = ft_argv_files(argv, argc, flags);
	directories = ft_argv_directories(argv, argc, flags);
	files_head = ft_list_files(files, argv, *flags, flag);
	ft_display_argv_files(files_head, *flags, flag, 0);
	if (ft_strlen(*flags) != 0 &&
	(argc == 2 || (files[0] == 0 && directories[0] == 0)))
	{
		ft_ls(".", *flags, 1, argc);
		block = 1;
	}
	if (files_head != NULL && directories[0] > 0)
		ft_printf("\n");
	if (block != 1)
		ft_process_directories(argv, argc, flags, flag);
	ft_free(files, directories, files_head);
}
