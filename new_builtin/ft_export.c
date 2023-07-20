/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:37:20 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/29 16:46:54 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	create_environment_var(char *token_str, t_list **env)
{
	t_list	*new_var;
	char	*new_var_str;

	new_var_str = ft_strdup(token_str);
	if (new_var_str == 0)
		quit_programm(EXIT_FAILURE);
	new_var = ft_lstnew(new_var_str);
	if (new_var == 0)
		quit_programm(EXIT_FAILURE);
	ft_lstadd_front(env, new_var);
}

t_list *get_sorted_env(t_list *env)
{
	t_list	*sorted_env;

	sorted_env = ft_lstdup(env);
	if (!sorted_env)
		quit_program(EXIT_FAILURE);
	ft_lst_sort_str(&sorted_env, ft_strcmp);
	return (sorted_env);
}

void	print_all_exported_vars (t_list *env)
{
	t_list	*sorted_env;
	t_list	*tmp;
	char	*env_str;
	int		i;

	sorted_env = get_sorted_env(env);
	tmp = sorted_env;
	while (tmp)
	{
		i = 0;
		env_str = (char *)tmp->content;
		if (ft_strchr(env_str, '='))
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			while (env_str[i] != '=')
				ft_putchar_fd(env_str[i++], STDOUT_FILENO);
			printf("=\"%s\"\n", &env_str[++i]);
		}
		else
			printf("declare -x %s\n", env_str);
		tmp = tmp->next;
	}
	ft_lstclear(&sorted_env, ft_lstdel_int);
}

int	ft_export(t_list *tokens, t_list **env)
{
	char	*var;
	char	*token_str;
	
	if (tokens == 0)
		print_all_exported_vars(*env);
	while (tokens)
	{
		token_str = tokens->content;
		if (!has_valid_identifier_export(token_str))
			return (EXIT_FAILURE);
	}
}