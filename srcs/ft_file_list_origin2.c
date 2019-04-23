/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_list_origin2.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:39:51 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:39:52 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_file_origin_id(struct stat *buf, t_file *new_link)
{
	if (getpwuid((*buf).st_uid) != NULL)
		new_link->owner = ft_strdup(getpwuid((*buf).st_uid)->pw_name);
	else
		new_link->owner = ft_itoa((*buf).st_uid);
	new_link->group = ft_strdup(getgrgid((*buf).st_gid)->gr_name);
}

void	ft_file_origin_date(struct stat *buf, t_file *new_link)
{
	new_link->month = ft_extract_date(ctime(&(*buf).st_mtime), 1);
	new_link->month_day = ft_extract_date(ctime(&(*buf).st_mtime), 2);
	new_link->hour_minute = ft_extract_date(ctime(&(*buf).st_mtime), 3);
	new_link->year = ft_extract_date(ctime(&(*buf).st_mtime), 4);
}

void	ft_file_origin_type(t_file *new_link)
{
	int val;

	val = ft_file_type(new_link->path);
	if (val == 1)
		new_link->type = '-';
	else if (val == 2)
		new_link->type = 'd';
	else if (val == 3)
		new_link->type = 'c';
	else if (val == 4)
		new_link->type = 'b';
	else if (val == 5)
		new_link->type = 'p';
	else if (val == 6)
		new_link->type = 'l';
	else if (val == 7)
		new_link->type = 's';
	else
		new_link->type = '?';
}

int		ft_isdevice(t_file *new_link)
{
	if (new_link->type == 'c' || new_link->type == 'b'
	|| new_link->type == 'p' || new_link->type == 's')
		return (1);
	return (0);
}

void	ft_file_origin_device(struct stat *buf, t_file *new_link)
{
	new_link->dev_major = major((*buf).st_rdev);
	new_link->dev_minor = minor((*buf).st_rdev);
	new_link->dev_layout = 1;
}
