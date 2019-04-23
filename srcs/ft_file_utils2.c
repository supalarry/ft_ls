/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_utils2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:42:33 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/20 16:42:34 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

int		ft_file_type(char *path)
{
	struct stat	path_stat;

	if (lstat(path, &path_stat) == -1)
		return (-1);
	if (S_ISREG(path_stat.st_mode) == 1)
		return (1);
	else if (S_ISDIR(path_stat.st_mode) == 1)
		return (2);
	else if (S_ISCHR(path_stat.st_mode) == 1)
		return (3);
	else if (S_ISBLK(path_stat.st_mode) == 1)
		return (4);
	else if (S_ISFIFO(path_stat.st_mode) == 1)
		return (5);
	else if (S_ISLNK(path_stat.st_mode) == 1)
		return (6);
	else if (S_ISSOCK(path_stat.st_mode) == 1)
		return (7);
	return (0);
}

int		ft_file_type2(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == -1)
		return (-1);
	if (S_ISREG(path_stat.st_mode) == 1)
		return (1);
	else if (S_ISDIR(path_stat.st_mode) == 1)
		return (2);
	else if (S_ISCHR(path_stat.st_mode) == 1)
		return (3);
	else if (S_ISBLK(path_stat.st_mode) == 1)
		return (4);
	else if (S_ISFIFO(path_stat.st_mode) == 1)
		return (5);
	else if (S_ISLNK(path_stat.st_mode) == 1)
		return (6);
	else if (S_ISSOCK(path_stat.st_mode) == 1)
		return (7);
	return (0);
}

void	ft_permissions_core(struct stat *buf, char *permissions)
{
	permissions[0] = ((buf->st_mode & S_IRUSR) ? 'r' : '-');
	permissions[1] = ((buf->st_mode & S_IWUSR) ? 'w' : '-');
	if (buf->st_mode & S_ISUID && buf->st_mode & S_IXUSR)
		permissions[2] = 's';
	else if (buf->st_mode & S_ISUID && !(buf->st_mode & S_IXUSR))
		permissions[2] = 'S';
	else
		permissions[2] = ((buf->st_mode & S_IXUSR) ? 'x' : '-');
	permissions[3] = ((buf->st_mode & S_IRGRP) ? 'r' : '-');
	permissions[4] = ((buf->st_mode & S_IWGRP) ? 'w' : '-');
	if (buf->st_mode & S_ISGID && buf->st_mode & S_IXGRP)
		permissions[5] = 's';
	else if (buf->st_mode & S_ISGID && !(buf->st_mode & S_IXGRP))
		permissions[5] = 'S';
	else
		permissions[5] = ((buf->st_mode & S_IXGRP) ? 'x' : '-');
	permissions[6] = ((buf->st_mode & S_IROTH) ? 'r' : '-');
	permissions[7] = ((buf->st_mode & S_IWOTH) ? 'w' : '-');
	if (buf->st_mode & S_ISVTX && buf->st_mode & S_IXOTH)
		permissions[8] = 't';
	else if (buf->st_mode & S_ISVTX && !(buf->st_mode & S_IXOTH))
		permissions[8] = 'T';
	else
		permissions[8] = ((buf->st_mode & S_IXOTH) ? 'x' : '-');
}

char	*ft_permissions(char *name, struct stat *buf)
{
	char	*permissions;
	ssize_t	xattr;
	acl_t	acl;

	permissions = (char *)malloc(11);
	xattr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	ft_permissions_core(buf, permissions);
	if (xattr > 0)
		permissions[9] = '@';
	else if (acl != NULL)
		permissions[9] = '+';
	else
		permissions[9] = ' ';
	if (acl != NULL)
		free(acl);
	permissions[10] = '\0';
	return (permissions);
}
