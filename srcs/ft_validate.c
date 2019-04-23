/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:52:16 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:52:17 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int	ft_validate(struct dirent *sd, int flag, char *flags)
{
	if (sd->d_name[0] != '.' || (flag == 1 && ft_strchr(flags, 'a')
	&& !ft_strchr(flags, 'R'))
	|| (!ft_dot(sd->d_name) && sd->d_name[0] == '.' && flag == 1
	&& ft_strchr(flags, 'a')))
		return (1);
	return (0);
}

int	ft_validate2(struct dirent *sd, int flag, char *flags)
{
	if (sd->d_name[0] == '.' && flag == 1 && ft_strchr(flags, 'a'))
		return (1);
	return (0);
}
