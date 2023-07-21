/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:41:30 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/21 13:22:28 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_delete_list_str(void *data)
{
	free(data);
	data = 0;
}

void	delete_env_var(char *var, t_list **env)
{
	t_list	*env_ptr;
	int		i;
	char	*cur_env;
	int		env_index;

	env_ptr = *env;
	env_index = 0;
	while (env_ptr)
	{
		i = 0;
		cur_env = (char *)(env_ptr->content);
		while (var[i] && cur_env[i] && (var[i] == cur_env[i]))
			i++;
		if (!var[i] && (cur_env[i] == '=' || cur_env[i] == '\0'))
		{
			ft_lstdel_node_nbr(env, env_index, ft_delete_list_str);
			return ;
		}
		env_index++;
		env_ptr = env_ptr->next;
	}
}

int	ft_unset(t_list *tokens, t_list **env)
{
	char *token_str;

	while (tokens)
	{
		token_str = tokens->content;
		if (!has_valid_identifier_unset(token_str))
			return (EXIT_FAILURE);
		if (has_only_one_cmd())
		{
			if (is_env_var(token_str, *env))
				delete_env_var(token_str, env);
		}
		tokens = tokens->next;
	}
	return (EXIT_SUCCESS);
}