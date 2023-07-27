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
	{
		tmp = ft_strdup(ft_strrchr(value, '/') + 1);
		if (!tmp)
			quit_program (EXIT_FAILURE);
		free (value);
		value = tmp;
		return (value);
	}
	else
		return (value);
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
			//find $ in token and replace with correct value.
			var = get_var_name(&str[0][i]);
			if (ft_strcmp(var, "$_") == 0)
				value = get_last_exec_name(var + 1);
			//in case of executables, like /bin/ls becomes ls
			else
				value = ft_getenv(var + 1);
			final = replace_midstring(*str, var, value, i);
			free(*str);
			*str = final;
			free (var);
			i += ft_strlen(value) - 1;
			if (value)
				free(value);
		}
	}
}

void	replace_env_single_token(char **token)
{
	t_list	*split_token;
	t_list	*tmp;
	char	*token_piece;

	split_token = get_split_token(*token);
	//split token in a link list for manipulation
	tmp = split_token;
	while (tmp)
	{
		token_piece = tmp->content;
		if (!ft_strcmp(token_piece, "~") || !ft_strcmp(token_piece, "~/", 2) \
			replace_tilde_with_home((char **)&tmp->content);
		// '~' expansion only occurs if tilde is first character or followed by '/'
		else if (*token_piece != '\'')
		{
			//expansion will not happen if it is inside single quote.
			if (*token_piece == '$' && ft_strcmp(token_piece, "$_") != 0 \
				&& ft_strcmp(token_piece, "$?") != 0 && *(token_piece + 1))
				replace_one_var((char **)&tmp->content);
			//the token piece is only $PATH or $TERM
			else
				replace_vars_with_values((char **)&tmp->content);
			replace_status_env((char **)&tmp->content, g_msh.exit_status);
		}
		delete_quotes((char *)tmp->content);
		tmp = tmp->next;
	}
	free(*token);
	*token = join_split_token(split_token);
}

void	replace_envs(t_list **tokens, t_list *redirs)
{
	//replace env variables by respective values in case of special characters.
	//'$' followed by env variable
	//'~' HOME directory
	//'$?' last exit status
	//	execpt for single quotes delimiter.
	t_list	*token;
	t_redir	*redir;

	token = *tokens;
	while (token)
	{
		//go through each token and replace in case there is $
		replace_env_single_token((char **)&token->content);
		token = token->next;
	}
	if (ft_lstsize(*tokens) > 1 && (char)*((char *)(*tokens)->content) != '\0')
		ft_lstclear_if(tokens, is_token_empty, free);
		//Del node that have an empty token after execution of replace_env_single_token()
		//e.g echo $WRONG_ENV
	while (redirs)
	{
		//go through each redirection and replace it in case there is a $
		redir = redirs->content;
		replace_env_single_token(&redir->direction);
		redirs = redirs->content;
	}
}