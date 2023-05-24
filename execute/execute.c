/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:18:38 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/24 15:34:52 by rtimsina         ###   ########.fr       */
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

int	exec_builtins_execve(t_ast_node *ptr, char ***env, t_elem *head, int *fd)
{
	pid_t	pid;

	pid = 0;
	if (check_builtins(ptr->content->cmd->args[0]) == 1)
		execute_builtins(ptr->content->cmd, env, head);
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
}