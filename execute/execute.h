/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:08:39 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/25 16:28:29 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//https://github.com/achrafelkhnissi/minishell/blob/d43f2a1d98a025366551205f6b1fcb551f447b0a/srcs/exec/execute.c

#ifndef EXECUTE_H
# define EXECUTE_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef enum e_bool
{
	false,
	true,
}	t_bool;

enum	e_token
{
	WORD = -1,
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	ESCAPE = '\\',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
	_NULL = '0',
};

enum e_shell_state
{
		SH_READING,
		SH_EXECUTING,
};

enum	e_state
{
	IN_DQUOTE,
	IN_QUOTE,
	ESCAPED,
	GENERAL,
};

enum e_node_type
{
	CMD,
	PIPE,
};

typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

/*
	desc; struct to store the command's dependencies.
	name: to store the full binary path or the commands name with
			or without options.
	args: to store the arguments needed for the command.
	redir: to store all the redirections if founded.
*/

typedef struct s_cmd
{
	char		**args;
	char		**env;
	t_fd		fd;
	t_redir_list	*redir;
}	t_cmd;

typedef struct s_pipe
{
	t_ast_node		*left;
	t_ast_node		*right;
}	t_pipe;

//union to store the different possibilities for an AST node.

typedef union u_union
{
	t_pipe	*pipe;
	t_cmd	*cmd;
}	t_union;

//struct to store an AST node.

typedef struct s_ast_node
{
	enum e_node_type	type;
	t_union				*content;
}	t_ast_node;

typedef struct s_ast
{
	t_ast_node	*root;
}	t_ast;

//a linked list element used to store a single token 
//returned from the lexer/tokenizer.

typedef struct s_elem
{
	char		*content;
	int			len;
	enum e_token	type;
	enum e_state	state;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

//doubly linked list to store the full command(lexer output)

typedef struct s_list
{
	t_elem	*head;
	t_elem	*tail;
	int		size;
}	t_list;

typedef struct s_data
{
	int				exit_status;
	enum e_shell_state	shell_state;
	char			*siglist[NSIG];
	int				pid;
	int				which;
	t_env			*ev;
	t_list			*lex;
	t_ast			*tree;
	int				alloc;
	char			**env;
}	t_data;

t_data		g_data;
typedef struct s_env_elem
{
	char		*key;
	char		*value;
	struct s_env_elem	*next;
	struct s_env_elem	*prev;
}	t_env_elem;

typedef struct s_env
{
	t_env_elem	*head;
	char		**env;
	int			size;
}	t_env;

//a linked list to store the redirections dependencies.
//it can be a "filename" or a "delimiter" for HERE_DOC
// < or > or << or >>.

typedef struct s_redir_elem
{
	char		*arg;
	enum e_token	type;
	t_redir_elem	*next;
}	t_redir_elem;

typedef struct s_redir_list
{
	t_redir_elem	*head;
	t_redir_elem	*tail;
	int				size;
}	t_redir_list;


int	ft_perror(char *msg, char *utils);
void	exec_redir_in(t_redir_elem *tmp, int *in);
void	exec_redir(t_redir_list *list, t_fd *fd);
int check_builtins(char *cmd);
int	exec_builtins_execve(t_ast_node *ptr, char ***env, t_elem *head, int *fd);
void	execute(t_ast_node *ptr, char ***env, int cmd_count, t_elem *head);
void	execute_builtins(t_cmd *cmd, char ***env, t_elem *head);
int	ft_strcmp(char *s1, char *s2);
char	*search_env_var(char *key, char **env);
char	*find_slash_dot(char *cmd, char **env);
char	*find_path(char *cmd, char **env);
char	*find_command(char *cmd, char **env);
int	*find_right_left(t_ast_node *ptr);

void	dup_fd(int *old, int new);
void	check_fd_builtins(t_cmd *cmd);
void check_fd_execve(t_cmd *cmd, int fd[2]);
int	execute_cmd(t_cmd *cmd, char ***env, int fd[2]);


#endif