/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:31 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/22 13:13:31 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

//Executes all the simple commands inside cmd_table;
//It does consecutively and redirecting input output of commands according
//to pipes redirection.

//Redirection have priority over pipes.


void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index)
{
	int	saved_stdin;
	int	saved_stdout;
	int	nb_cmds;

	nb_cmds = cmd_table->nb_cmds;
	replace_env(&cmd->tokens, cmd->redirs);
}

void	exec_cmd_table(t_cmd_table *cmd_table)
{
	t_list	*cmds;
	int		i;

	cmd_table->return_value = -1;
	cmds = cmd_table->cmds;
	cmd_table->nb_cmds = ft_lstsize(cmds);
	cmd_table->pipes = init_pipes(cmd_table->nb_cmds);
	i = 0;
	while (i < cmd_table->nb_cmds)
	{
		exec_cmd(cmds->content, cmd_table, i);
		cmds = cmds->next;
		i++;
	}
}

//executes all the command tables extracted by get_ast()
void	exec_ast(t_ast *ast)
{
	t_list	*cmd_table;
	char	*delimiter;

	cmd_table = ast->cmd_tables;
	while (cmd_table)
	{
		g_msh.curr_cmd_table = cmd_table->content;
		exec_cmd_table(g_msh.curr_cmd_table);
	}
}