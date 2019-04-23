/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 18:58:27 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/10 18:58:28 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int	main(int argc, char **argv)
{
	char	*flags;
	int		flag;
	int		ret;

	flags = NULL;
	flag = 0;
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], ".") == 0))
		ft_ls(".", NULL, 0, argc);
	else if (argv[1][0] == '-' && ft_strlen(argv[1]) > 1)
	{
		ret = ft_extract_flags(argv, &flags, argc);
		if (ret != 1)
		{
			ft_printf("./ft_ls: illegal option -- %c\n", ret);
			ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
			exit(1);
		}
		flag = 1;
	}
	if (argc != 1 && !(argc == 2 && ft_strcmp(argv[1], ".") == 0))
		ft_process_argv(argv, argc, &flags, flag);
	if (flags != NULL)
		free(flags);
}
