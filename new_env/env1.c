/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:07:43 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/23 11:07:43 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	replace_tilde_with_home(char **token)
{
	char	*home_path;

	home_path = ft_getenv("HOME");
	if (!token[0][1])
	{
		free(*token);
		*token = home_path;
	}
	else
		tilde_join(token, &home_path);
}

char	*get_last_exec_name(char *underscore)
{
	char	*value;
	char	*tmp;

	value = ft_getenv(underscore);
	if (is_path_executable(value))
}

void	replace_vars_with_values(cahr **str)
{
	int		i;
	char	*var;
	char	*value;
	char	*final;

	i = -1;
	while (str[0][++i])
	{
		if (str[0][i] == '$' && !ft_strchr("? ", str[0][i + 1]) && str[0][i + 1] != '\0')
		{
			var = get_var_name(&str[0][i]);
			if (ft_strcmp(var, "$_") == 0)
				value = get_last_exec_name(var + 1);
		}
	}
}

void	replace_env_single_token(char **token)
{
	t_list	*split_token;
	t_list	*tmp;
	char	*token_piece;

	split_token = get_split_token(*token);
	tmp = split_token;
	while (tmp)
	{
		token_piece = tmp->content;
		if (!ft_strcmp(token_piece, "~") || !ft_strcmp(token_piece, "~/", 2) \
			replace_tilde_with_home((char **)&tmp->content);
		else if (*token_piece != '\'')
		{
			if (*token_piece == '$' && ft_strcmp(token_piece, "$_") != 0 \
				&& ft_strcmp(token_piece, "$?") != 0 && *(token_piece + 1))
				replace_one_var((char **)&tmp->content);
			else
				replace_vars_with_values((char **)&tmp->content);
		}
	}
}

void	replace_envs(t_list **tokens, t_list *redirs)
{
	t_list	*token;
	t_redir	*redir;

	token = *tokens;
	while (token)
	{
		replace_env_single_token((char **)&token->content);
		token = token->next;
	}
	
}