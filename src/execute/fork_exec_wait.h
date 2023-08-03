/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec_wait.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:41:00 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 16:44:16 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_EXEC_WAIT_H
# define FORK_EXEC_WAIT_H

# include "main.h"

void	exec_child(char **tokens, char **envp, int nb_cmds, int **pipes, t_msh *g_msh);
void	exec_parent(t_list **pids, t_msh *g_msh);
void	close_all_pipes(int **pipes, int nb_cmds);

#endif
