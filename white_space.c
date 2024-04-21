/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:25:19 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/21 01:01:48 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_starting_ws(char *string)
{
	char	*ptr;
	char	*string_0;

	string_0 = string;
	string++;
	while (*string != '\0')
	{
		if (*string == ' ')
			string++;
		else
			break ;
	}
	ptr = ft_strdup(string);
	free(string_0);
	return (ptr);
}

char	*multiple_ws_to_single(char	*str)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
			cnt = 0;
		}
		else
		{
			cnt++;
			if (cnt <= 1)
			{
				str[j] = str[i];
				j++;
			}
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}