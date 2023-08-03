/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:04:57 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:13:59 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_PIPES_H
# define REDIRECTIONS_PIPES_H

# include "main.h"

int		**init_pipes(int nb_cmds, t_msh *g_msh);
void	set_redirs_pipes(t_list *redirs,
			t_cmd_table *cmd_table,
			int process_index, t_msh *g_msh);
int		has_redirs(t_list *redirs, char *type);
int		open_all_files(t_list *redirs, t_msh *g_msh);
int		open_file(t_redir *redir, int prev_fd, int flags, mode_t permissions, t_msh *g_msh);

#endif
