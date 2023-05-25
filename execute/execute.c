/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:18:38 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/25 16:29:39 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int check_builtins(char *cmd)
{
	if (cmd && (ft_strncmp(cmd, "export", 6) == 0))
		return (1);
	else if (cmd && (ft_strncmp(cmd, "unset", 5) == 0))
		return (1);
	else if (cmd && (ft_strncmp(cmd, "pwd", 3) == 0))
		return (1);
	else if (cmd && (ft_strncmp(cmd, "exit", 4) == 0))
		return (1);
	else if (cmd && (ft_strncmp(cmd, "cd", 2) == 0))
		return (1);
	else if (cmd && (ft_strncmp(cmd, "env", 3) == 0))
		return (1);
	else if (cmd && (ft_strncmp(cmd, "echo", 4) == 0))
		return (1);
	return (0);
}

void	check_last_pid(int pid, int count, int cmd_count)
{
	int		status;

	status = 0;
	if (count == cmd_count)
	{
		waitpid(pid, &status, 0);
		if (!g_data.which)
			g_data.exit_status = WEXITSTATUS(status);
	}
}

int	exec_builtins_execve(t_ast_node *ptr, char ***env, t_elem *head, int *fd)
{
	pid_t	pid;

	pid = 0;
	if (check_builtins(ptr->content->cmd->args[0]) == 1)
		execute_builtins(ptr->content->cmd, env, head);
	else
		pid = execute_cmd(ptr->content->cmd, *env, fd);
	return (pid);
}

void	execute(t_ast_node *ptr, char ***env, int cmd_count, t_elem *head)
{
	int		fd[2];
	int		pid;
	static int	count;

	pid = 0;
	if (ptr->type == CMD)
	{
		pid = exec_builtins_execve(ptr, env, head, fd);
		count++;
	}
	else if (ptr->type == PIPE)
	{
		if (pipe(fd) < 0)
			return ;
		if (ptr->content->pipe->right->type == CMD)
			dup_fd(&ptr->content->pipe->right->content->cmd->fd.out, fd[1]);
		else if (ptr->content->pipe->right->type == PIPE)
			dup_fd(find_right_left(ptr), fd[1]);
		dup_fd (&ptr->content->pipe->left->content->cmd->fd.in, fd[0]);
		execute(ptr->content->pipe->right, env, cmd_count, head);
		execute(ptr->content->pipe->left, env, cmd_count, head);
		close(fd[0]);
		close(fd[1]);
	}
	check_last_pid(pid, count, cmd_count);
}