/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:18:35 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 18:29:54 by rtimsina         ###   ########.fr       */
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