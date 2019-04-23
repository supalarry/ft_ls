/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_list_display.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:44:23 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:44:24 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_display_long_dev(t_file *head)
{
	if (ft_isdevice(head))
	{
		ft_printf("%*lu,", 3, head->dev_major);
		ft_printf("%*lu ", 4, head->dev_minor);
	}
	else if (!ft_dot(head->name))
	{
		ft_printf("%*c", 4, ' ');
		ft_printf("%*lu ", 4, head->dev_minor);
	}
	else
	{
		ft_printf("%*c", 4, ' ');
		ft_printf("%*lu ", 4, head->size);
	}
}

void	ft_display_long(t_file *head, int *widths)
{
	ft_printf("%c", head->type);
	ft_printf("%s ", head->permissions);
	ft_printf("%*d ", widths[0], head->hardlinks);
	ft_printf("%-*s  ", widths[1], head->owner);
	ft_printf("%-*s  ", widths[2], head->group);
	if (head->dev_layout == 0)
	{
		ft_printf("%*lu ", widths[3], head->size);
	}
	else if (head->dev_layout == 1)
	{
		ft_display_long_dev(head);
	}
	ft_printf("%*s ", 3, head->month);
	ft_printf("%*s ", 2, head->month_day);
	if (time(NULL) - head->last_mod > 15552000 ||
	head->last_mod > time(NULL))
		ft_printf("%*s ", 5, head->year);
	else
		ft_printf("%*s ", 5, head->hour_minute);
}

void	ft_display_files(t_file *head, int folder)
{
	int		widths[6];
	char	block[1024];
	int		len;

	if (head->l_flag == 1)
		ft_col_width(head, widths);
	if (head != NULL && head->l_flag == 1 && folder == 1)
		ft_printf("total %d\n", ft_blocks(head));
	while (head != NULL)
	{
		if (head->l_flag == 1 && head->err != 1)
			ft_display_long(head, widths);
		if (head->type == 'l')
		{
			len = readlink(head->path, block, sizeof(block) - 1);
			block[len] = '\0';
			ft_printf("%s -> %s\n", head->name, block);
		}
		else if (head->err != 1)
			ft_printf("%s\n", head->name);
		head = head->next;
	}
}

void	ft_display_files_rev(t_file *head, int folder)
{
	int		widths[6];
	char	block[1024];
	int		len;

	if (head->l_flag == 1)
		ft_col_width(head, widths);
	if (head != NULL && head->l_flag == 1 && folder == 1)
		ft_printf("total %d\n", ft_blocks(head));
	while (head->next != NULL)
		head = head->next;
	while (head != NULL)
	{
		if (head->l_flag == 1 && head->err != 1)
			ft_display_long(head, widths);
		if (head->type == 'l')
		{
			len = readlink(head->path, block, sizeof(block) - 1);
			block[len] = '\0';
			ft_printf("%s -> %s\n", head->name, block);
		}
		else if (head->err != 1)
			ft_printf("%s\n", head->name);
		head = head->prev;
	}
}
