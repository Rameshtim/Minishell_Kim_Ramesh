/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:11:35 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/22 13:11:35 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
#define EXECUTE_H

# include "../minishell1.h"

//redir_pipes.c
int	**init_pipes(int nb_cmds);
int	open_file(t_redir *redir, int prev_fd, int flags, mode_t permissions);
int	open_all_files(t_list *redirs);
int	has_redirs(t_list *redirs, char *type);
void	set_redirs_pipes(t_list *redirs, t_cmd_table *cmd_table, int process_index);

//execute.c
void	exec_cmd_table(t_cmd_table *cmd_table);
void	exec_ast(t_ast *ast);

//execute_utils.h
int	has_absolute_path(char *first_token);


#endif