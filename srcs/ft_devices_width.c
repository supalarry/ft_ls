/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_devices_width.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:33:33 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:33:35 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

size_t		ft_dev_major_width(t_file *head)
{
	size_t	width;

	width = 0;
	while (head != NULL)
	{
		if (ft_unum_len(head->dev_major) > width)
			width = ft_unum_len(head->dev_major);
		head = head->next;
	}
	return (width);
}

size_t		ft_dev_minor_width(t_file *head)
{
	size_t width;

	width = 0;
	while (head != NULL)
	{
		if (ft_unum_len(head->dev_minor) > width)
			width = ft_unum_len(head->dev_minor);
		head = head->next;
	}
	return (width);
}
