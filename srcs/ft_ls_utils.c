/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:59:09 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:59:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_pathname(char *pathname, char *path, char *d_name)
{
	pathname[0] = '\0';
	ft_strcat(pathname, path);
	if (ft_strcmp(pathname, "/") != 0
	&& pathname[ft_strlen(pathname) - 1] != '/')
		ft_strcat(pathname, "/");
	ft_strcat(pathname, d_name);
}

void	ft_dev_layout(t_file *head)
{
	int		dev_layout;
	t_file	*head_copy;

	dev_layout = 0;
	head_copy = head;
	while (head_copy != NULL)
	{
		if (head_copy->dev_layout == 1)
		{
			dev_layout = 1;
			break ;
		}
		head_copy = head_copy->next;
	}
	if (dev_layout == 1)
	{
		while (head != NULL)
		{
			head->dev_layout = 1;
			head = head->next;
		}
	}
}

void	ft_display(t_file *head, char *flags, int flag, int folder)
{
	if (head != NULL && flag == 1 && ft_strchr(flags, 'r') != NULL)
		ft_display_files_rev(head, folder);
	else if (head != NULL)
		ft_display_files(head, folder);
}

int		ft_dot(char *name)
{
	if (ft_strcmp(name, ".") == 0
	|| ft_strcmp(name, "..") == 0)
		return (1);
	return (0);
}

void	ft_print_name_err(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '\0')
		i++;
	while (path[i] != '/' && i >= 0)
		i--;
	i++;
	ft_putstr_fd(path + i, 2);
	ft_putstr_fd(": ", 2);
}
