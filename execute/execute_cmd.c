/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:38:08 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/24 17:12:23 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	dup_fd(int *old, int new)
{
	*old = new;
}

void	check_fd_builtins(t_cmd *cmd)
{
	if (cmd->fd.in != 0)
	{
		dup2(cmd->fd.in, STDIN_FILENO);
		close (cmd->fd.in);
	}
	if (cmd->fd.out != 1)
	{
		dup2(cmd->fd.out, STDOUT_FILENO);
		close(cmd->fd.out);
	}
}

void	execute_builtins(t_cmd *cmd, char ***env, t_elem *head)
{
	int	in;
	int	out;

	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	if (cmd->redir && cmd->redir->head)
		exec_redir(cmd->redir, &cmd->fd);
	if (cmd->fd.in == -1)
	{
		g_data.exit_status = 1;
		g_data.which = 1;
		return ;
	}
	check_fd_builtins(cmd);
	//ft_which_cmd(cmd, env, head);
	//have to work with builtins.
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	g_data.which = 1;
}

void check_fd_execve(t_cmd *cmd, int fd[2])
{
	if (cmd->fd.in != 0)
	{
		dup2(cmd->fd.in, STDIN_FILENO);
		close(cmd->fd.in);
		if (fd[0] != 0)
			close(fd[0]);
	}
	if (cmd->fd.out != 1)
	{
		dup2(cmd->fd.out, STDOUT_FILENO);
		close(cmd->fd.out);
		if (fd[0] != 1)
			close(fd[1]);
	}
}

int	execute_cmd(t_cmd *cmd, char ***env, int fd[2])
{
	char	*cm;
	int		pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		if (cmd->redir && cmd->redir->head)
		{
			exec_redir(cmd->redir, &cmd->fd);
			if (cmd->fd.in == -1)
				exit (1);
		}
		check_fd_execve(cmd, fd);
		cm = find_command(cmd->args[0], env);
	}
}