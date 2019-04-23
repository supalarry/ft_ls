/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_type.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 16:54:02 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/12 16:54:03 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

size_t	ft_blocks(t_file *head)
{
	size_t	blocks;

	blocks = 0;
	while (head != NULL)
	{
		blocks = blocks + head->blocks;
		head = head->next;
	}
	return (blocks);
}

void	ft_col_width(t_file *head, int *widths)
{
	widths[0] = ft_hardlinks_width(head);
	widths[1] = ft_owner_width(head);
	widths[2] = ft_group_width(head);
	widths[3] = ft_size_width(head);
	widths[4] = ft_dev_major_width(head);
	widths[5] = ft_dev_minor_width(head);
}

int		ft_index_file(char *flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (flags != NULL && flags[i] != '\0')
	{
		if (flags[i] == '-')
			count++;
		i++;
	}
	return (count);
}

void	ft_extract_part(char *extracted, char *timestamp, int len, int start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		extracted[i] = timestamp[start + j];
		i++;
		j++;
	}
	extracted[i] = '\0';
}

char	*ft_extract_date(char *timestamp, int value)
{
	char	*extracted;
	int		len;
	int		start;

	extracted = (char *)malloc(6);
	len = 0;
	start = 0;
	len = (value == 1 ? 3 : len);
	len = (value == 2 ? 2 : len);
	len = (value == 3 ? 5 : len);
	len = (value == 4 ? 4 : len);
	start = (value == 1 ? 4 : start);
	start = (value == 2 ? 8 : start);
	start = (value == 3 ? 11 : start);
	start = (value == 4 ? 20 : start);
	ft_extract_part(extracted, timestamp, len, start);
	return (extracted);
}
