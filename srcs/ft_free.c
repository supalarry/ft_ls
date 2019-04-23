/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:51:38 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:51:39 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_free_files(t_file *head)
{
	t_file	*ptr;

	while (head != NULL)
	{
		free(head->name);
		free(head->path);
		if (head->l_flag == 1)
		{
			free(head->permissions);
			free(head->owner);
			free(head->group);
			free(head->month);
			free(head->month_day);
			free(head->hour_minute);
			free(head->year);
		}
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

void	ft_free_folders(t_folder *head)
{
	t_folder	*ptr;

	while (head != NULL)
	{
		free(head->name);
		ptr = head;
		head = head->next;
		free(ptr);
	}
}
