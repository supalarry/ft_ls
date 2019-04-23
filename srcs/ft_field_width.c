/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_field_width.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 15:59:19 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/12 15:59:21 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

size_t		ft_unum_len(unsigned long long num)
{
	size_t len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

size_t		ft_hardlinks_width(t_file *head)
{
	size_t width;

	width = 0;
	while (head != NULL)
	{
		if (ft_unum_len(head->hardlinks) > width)
			width = ft_unum_len(head->hardlinks);
		head = head->next;
	}
	return (width);
}

size_t		ft_owner_width(t_file *head)
{
	size_t width;

	width = 0;
	while (head != NULL)
	{
		if (ft_strlen(head->owner) > width)
			width = ft_strlen(head->owner);
		head = head->next;
	}
	return (width);
}

size_t		ft_group_width(t_file *head)
{
	size_t width;

	width = 0;
	while (head != NULL)
	{
		if (ft_strlen(head->group) > width)
			width = ft_strlen(head->group);
		head = head->next;
	}
	return (width);
}

size_t		ft_size_width(t_file *head)
{
	size_t width;

	width = 0;
	while (head != NULL)
	{
		if (ft_unum_len(head->size) > width)
			width = ft_unum_len(head->size);
		head = head->next;
	}
	return (width);
}
