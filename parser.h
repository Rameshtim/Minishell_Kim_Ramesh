/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:00:37 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/17 15:23:18 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
#include "minishell.h"

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_parser_tools
{
	t_lexer			*lexer_list;
	t_lexer			*redirections;
	int				num_redirections;
	struct s_tools	*tools;
}	t_parser_tools;

typedef struct s_tools
{
	char					*args;
	char					**paths;
	char					**envp;
	struct s_simple_cmds	*simple_cmds;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}	t_tools;

typedef struct s_simple_cmds
{
	char					**str;
	int						(*builtin)(t_tools *, struct s_simple_cmds *)
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

#endif
