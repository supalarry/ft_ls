/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_ascii.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 16:53:19 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/12 16:53:20 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

void	ft_sort_ascii(int *array_ptr, int len, char **argv)
{
	int	i;
	int	temp_i;
	int	swap;

	i = 0;
	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(argv[array_ptr[i]], argv[array_ptr[i + 1]]) > 0)
			{
				temp_i = *(array_ptr + i);
				*(array_ptr + i) = *(array_ptr + i + 1);
				*(array_ptr + i + 1) = temp_i;
				swap = 1;
			}
			i++;
		}
		i = 0;
	}
}
