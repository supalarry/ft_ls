/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 13:46:47 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/14 13:46:49 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_sort_files(t_file **head, char *flags, int flag)
{
	ft_dev_layout(*head);
	if (*head != NULL)
	{
		*head = ft_ascii(*head);
		if (flag == 1 && ft_strchr(flags, 't') != NULL)
			*head = ft_time(*head);
	}
}

t_file	*ft_rewind(t_file *head)
{
	while (head != NULL && head->prev != NULL)
		head = head->prev;
	return (head);
}

t_file	*ft_ascii(t_file *head)
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
					ft_list_swap(head, head->next);
					swap = 1;
				}
				if (head->next != NULL)
					head = head->next;
			}
			head = ft_rewind(head);
		}
	}
	return (head);
}

t_file	*ft_time(t_file *head)
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
					ft_list_swap(head, head->next);
					swap = 1;
				}
				if (head->next != NULL)
					head = head->next;
			}
			head = ft_rewind(head);
		}
	}
	return (head);
}

void	ft_list_swap(t_file *left, t_file *right)
{
	t_file	*left_prev;
	t_file	*right_next;

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
