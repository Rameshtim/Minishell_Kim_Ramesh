/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:08:09 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 16:08:09 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_memory.h"

void	free_msh(t_msh *msh)
{
	//to free the memory of base struct.
	ft_dlstclear(&msh->input_history, free);
	ft_lstclear(&msh->dup_envp, free);
	//both input_history and dup_env have string
	//so passing free is enough
	if (msh->ast != 0)
		free_ast(msh->ast);
	//ast is a struct so we cannot just use free.
}

//Frees the Abstract Syntax Tree Struct
//all functions are passed to the ft_lstclear function as a function pointer
//to free each node. And also free the struct itself.
void	free_ast(t_ast *ast)
{
	ft_lstclear(&ast->cmd_tables, free_cmd_table);
	free(ast);
}

void	free_cmd_table(void *cmd_table)
{
	ft_lstclear(&((t_cmd_table *)cmd_table)->cmds, free_cmd);
	free(((t_cmd_table *)cmd_table)->delimiter);
	free(cmd_table);
}

void	free_cmd(void *cmd)
{
	ft_lstclear(&((t_cmd *)cmd)->tokens, free);
	ft_lstclear(&((t_cmd *)cmd)->redirs, free_redir);
	free(cmd);
}

void	free_redir(void *redir)
{
	free(((t_redir *)redir)->direction);
	free(redir);
}