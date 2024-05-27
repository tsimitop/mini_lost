/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:00 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/30 19:00:38 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_mini	*env_search_name(char *name, t_env_mini *env_mini)
{
	if (!name || !env_mini)
		return (0);
	while (env_mini)
	{
		if (inputis(env_mini->name, name))
			return (env_mini);
		if (env_mini->next)
			env_mini = env_mini->next;
		else
			break ;
	}
	return (0);
}

void	run_cd(char *inpt, t_shell *shell_info)
{
	char		*path_input;
	char		cwd[2048];
	t_env_mini	*env_mini;
	t_env_mini	*env_mini_pwd;
	t_env_mini	*env_mini_oldpwd;
  	t_env_mini  *env_mini_home;
  	char    **splitted;

  if (!inpt || !*inpt)
    return;
  splitted = ft_split(inpt, ' ');
  if (splitted[1])
  {
    *(shell_info->status) = 1;
	  printf("minishell: cd : too many arguments\n");
    return ;
  }

  getcwd(cwd, sizeof(cwd));
  env_mini_pwd = 0;
  env_mini_oldpwd = 0;
  env_mini_home = 0;
  env_mini_pwd = env_search_name("PWD", shell_info->env_mini);
  env_mini_oldpwd = env_search_name("OLDPWD", shell_info->env_mini);
  env_mini_home = env_search_name("HOME", shell_info->env_mini);
  path_input = inpt;
  if (inputis(inpt,"~"))
  {
		ft_memset(shell_info->oldpwd, 0, 2048);
		ft_strlcat(shell_info->oldpwd, shell_info->cwd, 2048);
		ft_memset(shell_info->cwd, 0, 2048);
		ft_strlcat(shell_info->cwd, env_mini_home->value, 2048);
    env_mini_pwd->value = shell_info->cwd;
	  if (env_mini_oldpwd)
	   	env_mini_oldpwd->value = shell_info->oldpwd;
	  else
	  {
	   	env_mini = ft_lstnew_envmini("OLDPWD", shell_info->oldpwd);
	   	ft_lstlast_envmini(shell_info->env_mini)->next = env_mini;
	  }
		*(shell_info->status) = 0;
  }
	else if (chdir(path_input) == -1)
	{
		*(shell_info->status) = 1;
	  	printf("minishell: cd : %s: No such file or directory\n", path_input);	
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		ft_memset(shell_info->oldpwd, 0, 2048);
		ft_strlcat(shell_info->oldpwd, shell_info->cwd, 2048);
		ft_memset(shell_info->cwd, 0, 2048);
		ft_strlcat(shell_info->cwd, cwd, 2048);
	  	env_mini_pwd->value = shell_info->cwd;
	  	if (env_mini_oldpwd)
	    	env_mini_oldpwd->value = shell_info->oldpwd;
	  	else
	  	{
	    	env_mini = ft_lstnew_envmini("OLDPWD", shell_info->oldpwd);
	    	ft_lstlast_envmini(shell_info->env_mini)->next = env_mini;
	  	}
		*(shell_info->status) = 0;
	}
}