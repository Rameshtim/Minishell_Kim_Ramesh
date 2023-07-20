/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:18:35 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/20 16:22:41 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell1.h"

int	has_only_one_cmd(void)
{
	int	check;

	if (ft_lstsize(g_msh.curr_cmd_table->cmds) == 1)
		check = 1;
	else
		check = 0;
	return (check);
}

char	*replace_env_value(char **env_ptr, char *var_name, char *new_value)
{
	char	*tmp;
	char	*final;

	tmp = ft_strjoin(var_name, "=");
	if (!tmp)
		quit_program(EXIT_FAILURE);
	final = ft_strjoin(tmp, new_value);
	if (!final)
		quit_program (EXIT_FAILURE);
	free (tmp);
	tmp = NULL;
	free (*env_ptr);
	env_ptr = NULL;
	return (final);
}

void	update_environment_var(char *var, char *new_value, t_list *env)
{
	int	i;
	char	*cur_env;

	while (env)
	{
		i = 0;
		cur_env = (char *)(env->content);
		while (var[i] && cur_env[i] && (var[i] == cur_env[i]))
			i++;
		if (!var[i] && (cur_env[i] == '=' || cur_env[i] == '\0'))
			env->content = replace_env_value(&cur_env, var, new_value);
		env = env->next;
	}
}

int update_directories(char *old_dir, t_list **env)
{
	char	new_dir[MAX_PATH];
	
	if (getcwd(new_dir, MAX_PATH) == NULL)
		return (EXIT_FAILURE);
	if (!is_env_var("PWD", *env))
		create_environment_var("PWD", *env);
	update_environment_var("PWD", new_dir, *env);
	if (!is_env_var("OLDPWD", *env))
		create_environment_var("OLDPWD", env);
	update_environment_var("OLDPWD", old_dir, *env);
	return (EXIT_SUCCESS);
}

int	is_token_valid_export (char *token_str, char *err_msg)
{
	int	check;

	if ((token_str[0] == '=') || ft_isdigit(token_str[0]) \
		|| ft_strchr(token_str, '\'') || ft_strchr(token_str, '"'))
	{
		check = 0;
		ft_strcpy(err_msg, "export: `");
		ft_strcat(err_msg, token_str);
		ft_strcat(err_msg, "': not a valid identifier");
	}
	else
		check = 1;
	return (check);
}

int	has_valid_identifier_export(char *token_str)
{
	char	err_msg[100];
	int		check;

	ft_bzero(err_msg, 0);
	if (!is_token_valid_export(token_str, err_msg));
	{
		check = 0;
		errno = ENOEXEC;
		//custom errorhandling. giving errno ENOEXEC explicitly before perror.
		write_minishell_error(err_msg);
	}
	else
		check = 1;
	return (check);
}