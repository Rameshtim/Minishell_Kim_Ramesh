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

//builtin functions are executed in parent process, functions like cd or export
// nteed to actually change env variables, so we can't execute them in a child process


void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index)
{
	int	saved_stdin;
	int	saved_stdout;
	int	nb_cmds;

	nb_cmds = cmd_table->nb_cmds;
	replace_envs(&cmd->tokens, cmd->redirs);
	//for token and redirections, replace env variable like $HOME by value
	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	set_redirs_pipes(cmd->redirs, cmd_table, process_index);
	if (g_msh.exit_status == EXIT_SUCCESS && cmd->tokens != 0)
	{
		if (is_builtin(cmd->tokens))
			exec_builtin(cmd->tokens, &g_msh.dup_envp, nb_cmds, process_index);
		else
			exec_programm(cmd->tokens, cmd_table);
	}
}

void	exec_builtin(t_list *tokens, t_list **env, int nb_cmds, int process_index)
{
	char	*program_name;

	program_name = tokens->content;
	if (ft_strcmp(program_name, "exit") == 0)
		g_msh.exit_status = ft_exit(tokens->next);
	else if (ft_strcmp(program_name, "echo") == 0)
		g_msh.exit_status = ft_echo(tokens->next);
	else if ((ft_strcmp(program_name, "env") == 0) && ft_lstsize(tokens) == 1)
		g_msh.exit_status = ft_env(tokens->next);
	else if (ft_strcmp(program_name, "cd") == 0)
		g_msh.exit_status = ft_cd(tokens->next, env);
	else if (ft_strcmp(program_name, "pwd") == 0)
		g_msh.exit_status = ft_pwd();
	else if (ft_strcmp(program_name, "export") == 0)
		g_msh.exit_status = ft_export(tokens->next, env);
	else if (ft_strcmp(program_name, "unset") == 0)
		g_msh.exit_status = ft_unset(tokens->next, env);
	if (process_index == nb_cmds - 1)
		g_msh.curr_cmd_table->return_value = g_msh.exit_status;
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

void	exec_program(t_list *lst_tokens, t_cmd_table *cmd_table)
{
	char	**tokens;
	char	**envp;
	pid_t	pid;
	t_list	*new_node;

	tokens = convert_list_to_arr(lst_tokens);
	envp = convert_list_to_arr(g_msh.dup_envp);
	pid = fork();
	if (pid < 0)
		quit_program(EXIT_FAILURE);
	else if (pid == 0)
		exec_child(tokens, envp, cmd_table->nb_cmds, cmd_table->pipes);
	new_node = ft_lstnew((void *)pid);
	if (!new_node)
		quit_program(EXIT_FAILURE);
	ft_lstadd_back(&cmd_table->pids, new_node);
	free(tokens);
	free(envp);
}