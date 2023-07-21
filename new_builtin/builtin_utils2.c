/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:43:44 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/21 13:20:27 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_token_valid_unset(char *token_str, char *err_msg)
{
	int	check;
	if (token_str == 0)
		return (1);
	if (ft_strchr(token_str, '=') || ft_strchr(token_str, '\'') \
		ft_strchr(token_str, '"') || ft_strchr(token_str, '$') \
		*token_str == '/' || ft_isdigit(*token_str))
	{
		check = 0;
		ft_strcpy(err_msg, "unset: `");
		ft_strcat(err_msg, token_str);
		ft_strcat(err_msg, "': not a valid identifier");
	}
	else
		check = 1;
	return (check);
}

int	has_valid_identifier_unset(char *token_str)
{
	char	err_msg[100];
	int		check;

	ft_bzero(err_msg, 0);
	if (!is_token_valid_unset(token_str, err_msg))
	{
		check = 0;
		errno = ENOEXEC;
		write_minishell_error(err_msg);
	}
	else
		check = 1;
	return (check);
}

int	has_only_one_cmd(void)
{
	int	check;

	if (ft_lstsize(g_msh.curr_cmd_table->cmds) == 1)
		check = 1;
	else
		check = 0;
	return (check);
}

void	ft_lstdel_node_nbr(t_list **lst, int node_nbr, void (*del)(void*))
{
	if (!lst)
		return ;
	if (node_nbr == 0)
		ft_lstdel_first(lst, del);
	else if (node_nbr == ft_lstsize(*lst) - 1)
		ft_lstdel_last(*lst, del);
	else if (node_nbr >= ft_lstsize(*lst))
		return ;
	else
		ft_lstdel_middle(lst, node_nbr, del);
	return ;
}

ft_lstdel_middle(t_list **lst, int node_nbr, void (*del)(void*))
{
	int		cur_node;
	t_list	*tmp;
	t_list	*to_delete;

	cur_node = 0;
	tmp = *lst;
	while (cur_node + 1 < node_nbr)
	{
		tmp = tmp->next;
		cur_node++
	}
	to_delete = tmp->next;
	tmp->next = to_delete->next;
	del(to_delete->content);
	free(to_delete);
}