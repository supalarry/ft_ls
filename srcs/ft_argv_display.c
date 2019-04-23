/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argv_display.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 18:44:12 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/22 18:44:14 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_display_argv_files(t_file *head, char *flags, int flag, int folder)
{
	if (head != NULL && flag == 1 && ft_strchr(flags, 'r') != NULL)
		ft_display_argv_rev(head, folder);
	else if (head != NULL)
		ft_display_argv(head, folder);
}

void	ft_display_argv(t_file *head, int folder)
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
			ft_printf("%s -> %s\n", head->path, block);
		}
		else if (head->err != 1)
			ft_printf("%s\n", head->path);
		head = head->next;
	}
}

void	ft_display_argv_rev(t_file *head, int folder)
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
			ft_printf("%s -> %s\n", head->path, block);
		}
		else if (head->err != 1)
			ft_printf("%s\n", head->path);
		head = head->prev;
	}
}
