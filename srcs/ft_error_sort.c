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

t_error	*ft_rewind_error(t_error *head)
{
	while (head != NULL && head->prev != NULL)
		head = head->prev;
	return (head);
}

t_error	*ft_ascii_error(t_error *head)
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
					ft_error_swap(head, head->next);
					swap = 1;
				}
				if (head->next != NULL)
					head = head->next;
			}
			head = ft_rewind_error(head);
		}
	}
	return (head);
}

void	ft_error_swap(t_error *left, t_error *right)
{
	t_error	*left_prev;
	t_error	*right_next;

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
