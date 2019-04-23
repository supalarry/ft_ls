/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_load_indexes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 17:04:59 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/12 17:05:00 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int		*ft_argv_files(char **argv, int argc, char **flags)
{
	int	i;
	int	fi;
	int	*files;

	i = 1 + ft_dashcount(*flags);
	fi = 0;
	files = (int *)malloc(sizeof(int) * 127);
	while (i < argc)
	{
		if (ft_file_type(argv[i]) != 2 &&
		((*flags != NULL && ft_strchr(*flags, 'l'))
		|| ft_file_type2(argv[i]) != 2) && ft_file_type(argv[i]) != -1)
		{
			files[fi] = i;
			fi++;
		}
		i++;
	}
	ft_sort_ascii(files, fi, argv);
	files[fi] = -fi;
	if (*flags != NULL && ft_strchr(*flags, 't'))
		ft_time_directories(argv, files);
	return (files);
}

void	ft_time_directories(char **argv, int *directories)
{
	int			i;
	t_folder	*head;
	t_folder	*head_copy;

	i = 0;
	head = NULL;
	while (directories[i] > 0)
	{
		if (head == NULL)
			head = ft_folder_origin(argv[directories[i]], NULL, directories[i]);
		else
			ft_folder_append(head, argv[directories[i]], directories[i]);
		i++;
	}
	head = ft_time_subfolders(head);
	head_copy = head;
	i = 0;
	while (head != NULL)
	{
		directories[i] = head->index;
		head = head->next;
		i++;
	}
	if (head_copy != NULL)
		ft_free_folders(head_copy);
}

int		*ft_argv_directories(char **argv, int argc, char **flags)
{
	int	i;
	int	di;
	int	*directories;

	i = 1 + ft_dashcount(*flags);
	di = 0;
	directories = (int *)malloc(sizeof(int) * 127);
	while (i < argc)
	{
		if (ft_file_type(argv[i]) == 2 ||
		(ft_file_type2(argv[i]) == 2 &&
		!(*flags != NULL && ft_strchr(*flags, 'l'))))
		{
			directories[di] = i;
			di++;
		}
		i++;
	}
	ft_sort_ascii(directories, di, argv);
	directories[di] = -di;
	if (*flags != NULL && ft_strchr(*flags, 't'))
		ft_time_directories(argv, directories);
	return (directories);
}
