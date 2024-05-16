/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:20:48 by yowoo             #+#    #+#             */
/*   Updated: 2023/10/17 12:38:30 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// return ((c >= '0' && c <= '9')? 1:0);
// #include <stdio.h>
// int main(){
//     int result = ft_isdigit('a');
//     printf("%d",result);
// }