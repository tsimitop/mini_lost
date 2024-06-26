/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:25:19 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/21 15:21:13 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_starting_ws(char *string)
{
	char	*ptr;

	while (string && *string)
	{
		if (*string == ' ')
			string++;
		else
			break ;
	}
	ptr = ft_strdup(string);
	return (ptr);
}

void	cpy_chars(char *str, int *i, int *j)
{
	int	cnt;

	cnt = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] != ' ')
		{
			str[*j] = str[*i];
			j++;
			cnt = 0;
		}
		else
		{
			cnt++;
			if (cnt <= 1)
			{
				str[*j] = str[*i];
				j++;
			}
		}
		i++;
	}
}

char	*multiple_ws_to_single(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cpy_chars(str, &i, &j);
	str[j] = '\0';
	return (str);
}

char	*ptr_ws(char *inpt)
{
	char	*ptr;

	ptr = inpt;
	while (*ptr)
	{
		if (is_ws(*ptr))
			return (ptr);
		ptr++;
	}
	return (0);
}
