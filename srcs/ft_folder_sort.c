/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_folder_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:46:08 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:46:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void		ft_sort_folders(t_folder **head, char *flags, int flag)
{
	if (*head != NULL)
	{
		*head = ft_ascii_subfolders(*head);
		if (flag == 1 && ft_strchr(flags, 't') != NULL)
			*head = ft_time_subfolders(*head);
	}
}

t_folder	*ft_rewind_subfolder(t_folder *head)
{
	while (head != NULL && head->prev != NULL)
		head = head->prev;
	return (head);
}

t_folder	*ft_ascii_subfolders(t_folder *head)
{
	int	swap;

	swap = 1;
	if (head != NULL)
	{
		while (swap == 1)
		{
			swap = 0;
			while (head != NULL && head->next != NULL)
			{
				if (ft_strcmp(head->name, head->next->name) > 0)
				{
					ft_list_swap_subfolder(head, head->next);
					swap = 1;
				}
				if (head->next != NULL)
					head = head->next;
			}
			head = ft_rewind_subfolder(head);
		}
	}
	return (head);
}

t_folder	*ft_time_subfolders(t_folder *head)
{
	int	swap;

	swap = 1;
	if (head != NULL)
	{
		while (swap == 1)
		{
			swap = 0;
			while (head != NULL && head->next != NULL)
			{
				if (head->last_mod < head->next->last_mod)
				{
					ft_list_swap_subfolder(head, head->next);
					swap = 1;
				}
				if (head->next != NULL)
					head = head->next;
			}
			head = ft_rewind_subfolder(head);
		}
	}
	return (head);
}

void		ft_list_swap_subfolder(t_folder *left, t_folder *right)
{
	t_folder	*left_prev;
	t_folder	*right_next;

	left_prev = left->prev;
	right_next = right->next;
	left->next = right_next;
	left->prev = right;
	if (right_next != NULL)
		right_next->prev = left;
	right->next = left;
	right->prev = left_prev;
	if (left_prev != NULL)
		left_prev->next = right;
}
