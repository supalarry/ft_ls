/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_list_origin1.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:39:45 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:39:46 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_fill_file_name(char *path, char *name, int i, int j)
{
	while (path[i] != '\0')
	{
		name[j] = path[i];
		j++;
		i++;
	}
	name[j] = '\0';
}

char	*ft_file_name(char *path)
{
	int		i;
	int		j;
	int		len;
	char	*name;

	i = 0;
	j = 0;
	len = 0;
	while (path[i] != '\0')
		i++;
	while (path[i] != '/' && i >= 0)
	{
		i--;
		len++;
	}
	i++;
	name = (char *)malloc(len + 1);
	ft_fill_file_name(path, name, i, j);
	return (name);
}

void	ft_file_origin_basics(t_file *new_link, t_file *prev, char *name)
{
	new_link->name = ft_file_name(name);
	new_link->path = ft_strdup(name);
	new_link->prev = prev;
	new_link->next = NULL;
	new_link->l_flag = 0;
	new_link->err = 0;
	new_link->dev_major = 0;
	new_link->dev_minor = 0;
	new_link->dev_layout = 0;
}
