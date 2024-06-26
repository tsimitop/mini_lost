/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:18:23 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/26 13:32:33 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//pwd asdf => pwd should work 
void	run_pwd(t_shell *shell_info)
{
	printf("%s\n", shell_info->cwd);
	proc_exit(0, shell_info);
}
