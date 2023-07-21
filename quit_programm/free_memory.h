/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:08:35 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 16:08:35 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEMORY_H
# define FREE_MEMORY_H

#include "../minishell1.h"

void	free_msh(t_msh *msh);
void	free_ast(t_ast *ast);
void	free_cmd_table(void *cmd_table);
void	free_cmd(void *cmd);
void	free_redir(void *redir);

#endif