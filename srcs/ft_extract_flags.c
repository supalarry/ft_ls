/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_extract_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:48:51 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:48:53 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int		ft_invalid_flag(char flag)
{
	if (flag != 'l' && flag != 'R'
	&& flag != 'a' && flag != 'r'
	&& flag != 't' && flag != '1')
		return (1);
	return (0);
}

void	ft_save_flag(char **flags, char flag, int *j)
{
	if (ft_strchr(*flags, flag) == NULL)
	{
		(*flags)[*j] = flag;
		(*j)++;
	}
}

char	ft_extract_flags(char **argv, char **flags, int argc)
{
	int i;
	int j;
	int k;

	i = 1;
	k = 1;
	j = 0;
	*flags = (char *)malloc(20);
	ft_bzero(*flags, 20);
	while (k < argc && argv[k][0] == '-')
	{
		(*flags)[j] = argv[k][0];
		j++;
		while (argv[k][i] != '\0')
		{
			if (ft_invalid_flag(argv[k][i]))
				return (argv[k][i]);
			ft_save_flag(flags, argv[k][i], &j);
			i++;
		}
		i = 1;
		k++;
	}
	return (1);
}
