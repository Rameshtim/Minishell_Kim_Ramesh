/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:18:55 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/27 12:08:56 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

char	*get_value_name(char *str)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && !is_token_delimiter(str[i]) && str[i] != '$' && str[i] != '=')
		i++;
	i++;
	len = ft_strlen(str) - i;
	value = ft_substr(str, i, len);
	if (!value)
		quit_program(EXIT_FAILURE);
	return (value);
}

int	is_token_empty(void *data)
{
	int		check;
	char	*token;

	token = data;
	if (*token == '\0')
		check = 1;
	else
		check = 0;
	return (check);
}

void	replace_string(char *src, char **dest)
{
	char	*temp;

	temp = ft_strdup(src);
	if (temp == 0)
		quit_program(EXIT_FAILURE);
	free(*dest);
	*dest = 0;
	*dest = temp;
}

void	unset_oldpwd(void)
{
	if (is_env_var("OLDPWD", g_msh.dup_envp) == 0)
		create_environment_var("OLDPWD", &g_msh.dup_envp);
	else
		remove_env_value("OLDPWD");
}

void	increment_shlvl(void)
{
	//update shell level everytime we call ./minishell
	char	*cur_lvl;
	int		lvl_nbr;

	if (is_env_var("SHLVL", g_msh.dup_envp) == 0)
		create_environment_var("SHLVL=1", &g_msh.dup_envp);
	//if variable unset we create it and set to 1
	else
	{
		//we increment 1 everytime we call ./minishell
		cur_lvl = ft_getenv("SHLVL");
		lvl_nbr = ft_atoi(cur_lvl);
		lvl_nbr++;
		free(cur_lvl);
		cur_lvl = ft_atoi(lvl_nbr);
		if (cur_lvl == 0)
			quit_program(EXIT_FAILURE);
		update_environment_var("SHLVL", cur_lvl, g_msh.dup_envp);
		free(cur_lvl);
	}
}