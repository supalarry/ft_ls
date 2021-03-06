/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:25:13 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 13:25:14 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*fresh_string;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		fresh_string = (char *)malloc(len + 1);
		if (fresh_string != NULL)
		{
			while (i < len)
			{
				fresh_string[i] = (*f)(i, s[i]);
				i++;
			}
			fresh_string[i] = '\0';
		}
	}
	else
	{
		fresh_string = NULL;
	}
	return (fresh_string);
}
