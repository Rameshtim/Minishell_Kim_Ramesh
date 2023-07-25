/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:23:21 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/22 13:23:21 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	**init_pipes(int nb_cmds)
{
	int	**pipes;
	//create 2d array of pipes, where it will have 2 ints.
	// [0] reading end of pipe
	// [1] writing end of pipe.
	int	i;

	if (nb_cmds == 1)
		return (0);
	pipes = ft_calloc(nb_cmds, sizeof(int *));
	if (!pipes)
		quit_program(EXIT_FAILURE);
	i = 0;
	while (i < nb_cmds - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (|!pipes[i])
			quit_program(EXIT_FAILURE);
		if (pipe(pipes[i]) == -1)
			quit_program(EXIT_FAILURE);
		i++;
	}
	return (pipes);
}

int	open_file(t_redir *redir, int prev_fd, int flags, mode_t permissions)
{
	char	*file_name;
	int		new_fd;

	if (prev_fd != -2)
		close(prev_fd);
	file_name = redir->direction;
	new_fd = open(file_name, flags, permissions);
	if (new_fd == -1)
	{
		write_minishell_exec_error(file_name, strerror(errno));
		g_msh.exit_status = errno;
	}
	else
	{
		if (!ft_strcmp(redir->type, "<"))
			dup2(new_fd, STDIN_FILENO);
		//if redirection is "<" then standard input will be new_fd.
		else if (!ft_strcmp(redir->type, ">") || !ft_strcmp(redir->type, ">>"))
			dup2(new_fd, STDOUT_FILENO);
		//if redirection is "> | >>" standard output will be new_fd.
		close(new_fd);
		//while opening file new_fd will get lowest possible int to point the opened file
		//after finding redirection either STDIN or STDOUT will be given to new_fd
		//therefore closing original new_fd should be done manually.
	}
	return (new_fd);
}

int	open_all_files(t_list *redirs)
{
	int	fd_i;
	int	fd_o;
	t_redir	*redir;

	fd_i = -2;
	fd_o = -2;
	//initial state initialized to -2 because -1 is known as error for fd and 0 as input.
	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		if (!ft_strcmp(redir->type, "<"))
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
		else if (!ft_strcmp(redir->type, ">"))
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (!ft_strcmp(redir->type, ">>"))
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd_i == -1 || fd_o == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	has_redirs(t_list *redirs, char *type)
{
	int		check;
	t_redir	*redir;

	check = 0;
	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		if (!ft_strcmp(redir->type, type))
		{
			check = 1;
			break ;
		}
		redirs = redirs->next;
	}
	return (check);
}

//parses redirs and open all relevant files. In case there are more than one
//redirection of input or output, keep only last one.
//we only need to set piping if there are no redirections.
//if first process than no piping.
//we read from the pipe (process_index - 1)(0) because the previous index 
//write to that same pipe but to its writing end [1]
//if last process than no piping
//so write to [1] so that next cmd can read from this end. 
void	set_redirs_pipes(t_list *redirs, t_cmd_table *cmd_table, int process_index)
{
	int	**pipes;
	int	nb_cmds;

	pipes = cmd_table->pipes;
	nb_cmds = cmd_table->nb_cmds;
	if (open_all_files(redirs) == EXIT_FAILURE)
		return ;
	if (!has_redirs(redirs, "<") && process_index != 0)
		dup2(pipes[process_index - 1][0], STDIN_FILENO);
	if (!has_redirs(redirs, ">") && !has_redirs(redirs, ">>") && process_index != nb_cmds - 1)
		dup2(pipes[process_index][1], STDOUT_FILENO);
	g_msh.exit_status = EXIT_SUCCESS;
}