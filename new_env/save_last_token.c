/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_last_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:35:09 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 17:58:23 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	*ft_lst_get_data_last_node(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst->content);	
}

//checks if first token has a relative path like ./a.out
int	has_relative_path(char *first_token)
{
	int	check;

	if (*first_token == '.')
		check = 1;
	else
		check = 0;
	return (check);
}

char	*convert_to_path(char *token)
{
	char	*token_path;

	if (has_relative_path(token))
	{
		token_path = ft_strdup(token);
		if (!token_path)
			quit_program(EXIT_FAILURE);
	}
	else
		token_path = get_absolute_path(token);
	return (token_path);
}

void	save_last_token(t_cmd_table *cmd_table)
{
	t_cmd	*last_simple_cmd;
	char	*last_token;
	char	*exec_path;

	last_simple_cmd = ft_lst_get_data_last_node(cmd_table->cmds);
	last_token = ft_lst_get_data_last_node(last_simple_cmd->tokens);
	if (last_token && has_only_one_cmd())
		exec_path = convert_to_path(last_token);
	else
	{
		exec_path = ft_strdup("");
		if (!exec_path)
			quit_program(EXIT_FAILURE);
	}
	update_environment_var("_", exec_path, g_msh.dup_envp);
	free(exec_path);
}