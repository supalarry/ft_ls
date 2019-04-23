/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argv_error.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 14:27:03 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/22 14:27:04 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_header.h"

t_error	*ft_error_origin(char *name, t_error *prev)
{
	t_error	*new_error;

	new_error = (t_error *)malloc(sizeof(t_error));
	new_error->name = ft_strdup(name);
	new_error->prev = prev;
	new_error->next = NULL;
	return (new_error);
}

void	ft_error_append(t_error *head, char *name)
{
	while (head->next != NULL)
		head = head->next;
	head->next = ft_error_origin(name, head);
}

void	ft_error_print(t_error *head)
{
	t_error	*temp;

	while (head != NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(head->name, 2);
		free(head->name);
		ft_putstr_fd(": ", 2);
		perror("");
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_error_argv(char **argv, int argc, char *flags)
{
	int		i;
	t_error	*head;

	i = 1 + ft_index_file(flags);
	head = NULL;
	while (i < argc)
	{
		if (ft_file_type(argv[i]) == -1)
		{
			if (head == NULL)
				head = ft_error_origin(argv[i], NULL);
			else
				ft_error_append(head, argv[i]);
		}
		i++;
	}
	head = ft_ascii_error(head);
	ft_error_print(head);
}
