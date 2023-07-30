/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:14:26 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/29 18:14:26 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <signal.h>


void	close_all_pipes(int **pipes, int nb_cmds)
{
	//close all pipes that were initiated in init_pipes()
	int	i;
	int	nb_pipes;

	i = 0;
	nb_pipes = nb_cmds - 1;
	while (i < nb_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	exec_child(char **tokens, char **envp, int nb_cmds, int **pipes)
{
	char	*exec_path;

	signal(SIGINT, SIG_DFL);
	close_all_pipes(pipes, nb_cmds);
	//we close all pipes because stdout and stdin already changed in set_redirs_pipes()
	//all pipes opened in parent process are also considered open in child but closing them
	//in child doesn't close them in parent.
	if (has_relative_path(tokens[0]) || has_absolute_path(tokens[0]))
	{
		exec_path = ft_strdup(tokens[0]);
		if (!exec_path)
			quit_program(EXIT_FAILURE);
	}
	else
		exec_path = get_absolute_path(tokens[0]);
	execve(exec_path, tokens, envp);
	if (errno == EACCES)
		write_minishell_exec_error(tokens[0], "Permission denied");
	else if (errno == ENOENT && ft_strcmp(tokens[0], "exit") != 0)
		write_minishell_exec_error(tokens[0], "Command not found");
	free(exec_path);
	free(tokens);
	free(envp);
	if (errno == EACCES)
		exit(EXIT_CMD_INTERRUPTED);
	else if (errno == ENOENT)
		exit(EXIT_CMD_NOT_FOUND);
	exit (errno);
}

void	exec_parent(t_list **pids)
{
	//wait for all child process to finish and sets the exit status.
	//child process may have existed even by signal like CTRL-C.
	//so helps to set the exit status.
	long	pid;
	int		exit_info;

	exit_info = 0;
	while (*pids)
	{
		pid = (long)(*pids)->content;
		waitpid(pid, &exit_info, 0);
		if (WIFEXITED(exit_info))
			g_msh.exit_status = WEXITSTATUS(exit_info);
		else if (WIFSIGNALED(exit_info))
			g_msh.exit_status = WTERMSIG(exit_info);
		ft_lstdel_first(pids, ft_lstdel_int);
	}
	
}
