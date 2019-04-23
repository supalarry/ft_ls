/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_path.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:50:07 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:50:08 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int		ft_dashcount(char *flags)
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

void	ft_print_path_r(int argc, int dashes, int *times, char *path)
{
	if ((argc == 3 + dashes || argc == 2 + dashes) && *times == 0)
		(*times)++;
	else if (argc != 3 + dashes && *times == 0 && ft_strcmp(path, ".") != 0)
	{
		ft_printf("%s:\n", path);
		(*times)++;
	}
	else if (ft_strcmp(path, ".") != 0)
		ft_printf("\n%s:\n", path);
}

void	ft_print_path_etc(int *times, char *path)
{
	if (*times == 0)
	{
		ft_printf("%s:\n", path);
		(*times)++;
	}
	else
		ft_printf("\n%s:\n", path);
}

void	ft_print_path(char *path, int flag, int argc, char *flags)
{
	static int	times;
	static int	check;
	static int	dashes;

	if (times == 0)
		dashes = ft_dashcount(flags);
	if (dashes > 1)
		dashes = (dashes - 1);
	else
		dashes = 0;
	if (path == NULL && flag == 0 && argc == 0)
		check = 0;
	if (check == 0 && flag == 1 && ft_strchr(flags, 'R'))
	{
		ft_print_path_r(argc, dashes, &times, path);
		check++;
	}
	else if (check == 0 && ((flag == 0 && argc > (2 + dashes))
	|| (flag == 1 && argc > (3 + dashes))))
	{
		ft_print_path_etc(&times, path);
		check++;
	}
}
