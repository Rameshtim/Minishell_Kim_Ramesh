/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:17:43 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/01 12:17:43 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	only_cd_errors(t_list *tokens)
{
	//print errors to stderror (without executing cd) in case of multiple commands
	//by using a combination of opendir and stat.
	char	*arg;
	int		status;

	status = 0;
	if (tokens == 0)
		status = cd_env_error_check("HOME");
	else if (tokens->next != 0)
		status = cd_error_message("cd", "too many arguments");
	else
	{
		arg = tokens->content;
		if (ft_strcmp(arg, "-") == 0);
			status = cd_env_error_check ("OLDPWD");
		else
			status = cd_path_error_check(arg);
	}
	return (status);
}

int	ft_cd(t_list *tokens, t_list **env)
{
	char	pwd[MAX_PATH];

	if (getcwd(pwd, MAX_PATH) == NULL)
	{//get current working directory (builtin)
		write_minishell_exec_error("cd", strerror(errno));
		//strerror is used to retrieve the error string associated with the error code.
		return (errno);
	}
	if (!has_only_one_cmd())
		return (only_cd_errors(tokens));
	else
		return (execute_cd(tokens, env, pwd));
}

int	execute_cd(t_list *tokens, t_list **env, char *pwd)
{
	char	*arg;
	int		status;

	if (tokens == 0)
		status = change_dir_home(pwd, env);
	else if (tokens->next != 0)
		status = cd_error_message("cd", "too many arguments");
	else
	{
		arg = tokens->content;
		if (chdir(arg) == EXIT_SUCCESS)
			status = update_directories(pwd, env);
		else if (!ft_strcmp(arg, "-"))
			status = change_to_old_dir(pwd, env);
		else
			status = other_invalid_error("cd", errno, arg);
	}
	return (status);
}

int	change_dir_home (char *cur_pwd, t_list **env)
{
	int	status;
	char	*home;

	home = ft_getenv("HOME");
	if (home == 0)
	{
		write_minishell_exec_error("cd", "HOME not set");
		status = EXIT_FAILURE;
	}
	else if (*home == '\0')
		status = EXIT_SUCCESS;
	else
	{
		if (chdir(home) == 0)
			status = update_directories(cur_pwd, env);
		else
			status = other_invalid_error("cd", errno, home);
		home = EXIT_SUCCESS;
	}
	if (home)
		free (home);
	return (status);
}

int	change_to_old_dir(char *cur_pwd, t_list **env)
{
	char	*old_dir;
	int		status;

	old_dir = ft_getenv("OLDPWD");
	if (old_dir == 0 || *old_dir == '\0')
	{
		write_minishell_exec_error("cd", "OLDPWD not set");
		status = EXIT_FAILURE;
	}
	else
	{
		if (chdir(old_dir) == 0)
		{
			printf("%s\n", old_dir);
			status = update_directories(cur_pwd, env);
		}
		else
			status = other_invalid_error("cd", errno, old_dir);
	}
	if (old_dir)
		free(old_dir);
	return (status);
}