/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:06 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 16:47:20 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "main.h"

void	exec_ast(t_ast *ast, t_msh *g_msh);
void	exec_cmd_table(t_cmd_table *cmd_table, t_msh *g_msh);
void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index, t_msh *g_msh);
void	exec_builtin(t_list *tokens,
			t_list **env,
			int nb_cmds,
			int process_index, t_msh *g_msh);
void	exec_program(t_list *lst_tokens, t_cmd_table *cmd_table, t_msh *g_msh);

#endif
