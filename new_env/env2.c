/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:06:00 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 18:21:54 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../new_builtin/builtin.h"
#include "../minishell1.h"
#include "environment.h"

char	*ft_getenv(char *key)
{
	int		i;
	t_list	*envp;
	char	*curr_envp;
	char	*value;

	envp = g_msh.dup_envp;
	while (envp)
	{
		i = 0;
		curr_envp = (char *)envp->content;
		while (key[i] && curr_envp[i] && (key[i] == curr_envp))
			i++;
		if (!key[i] && (curr_envp[i] == '=' || curr_envp[i] == '\0'))
		{
			value = ft_strdup(&(curr_envp[i + 1]));
			if (!value)
				quit_program(EXIT_FAILURE);
			return (value);
		}
		envp = envp->next;
	}
	return (NULL);
}

void	duplicate_env(t_list **dup_envp, char **envp)
{
	//create a copy of the envp string array so that it can be
	//manipulated throughout our programm
	t_list	*next_env;
	int		i;
	char	*tmp;

	if (!envp || !envp[0])
		quit_program(EXIT_FAILURE);
	i = 0;
	while (envp[i] != NULL)
	{
		tmp = ft_strdup(envp[i]);
		if (!tmp)
			quit_program(EXIT_FAILURE);
		next_env = ft_lstnew(tmp);
		if (!next_env)
			quit_program(EXIT_FAILURE);
		ft_lstadd_back(dup_envp, next_env);
		i++;
	}
}

void	remove_env_value(char *key)
{
	//to unassign an environment variable.
	int		i;
	t_list	*envp;
	char	*curr_envp;

	envp = g_msh.dup_envp;
	while (envp)
	{
		i = 0;
		curr_envp = (char *)envp->content;
		while (key[i] && curr_envp[i] && (key[i] == curr_envp[i]))
			i++;
		if (!key[i] && curr_envp[i] == '=')
		{
			replace_string(key, &curr_envp);
			envp->content = curr_envp;
		}
		envp = envp->next;
	}
}

void	replace_status_env(char **str, int last_status)
{
	//replaces token containing substr "$?" by the exit status of the 
	//last executed function
	int		replace_spot;
	char	*status_string;
	char	*final;

	replace_string = ft_strnstr_iterator(*str, "$?", ft_strlen(*str));
	while (replace_spot != -1)
	{
		status_string = ft_itoa(last_status);
		if (status_string == 0)
			quit_program(EXIT_FAILURE);
		final = replace_midstring(*str, "$?", status_string, replace_spot);
		free(status_string);
		status_string = 0;
		free(*str);
		*str = final;
		replace_spot = ft_strnstr_iterator(*str, "$?", ft_strlen(*str));
	}
}

int	is_path_executable(cahr *exec_file)
{
	struct stat statbuf;

	if (has_absolute_path(exec_file) && (stat(exec_file, &statbuf) == EXIT_SUCCESS \
		|| S_ISREG(statbuf.st_mode)))
		return (1);
	else
		return (0)
}