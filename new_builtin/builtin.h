/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:30:53 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/01 09:30:53 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define EXIT_GENERAL_ERROR 2
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CMD_INTERRUPTED 130
# define EXIT_ERROR_FORMAT 258
#define MAX_PATH 1024

#include <termcap.h>
#include <stdlib.h>
#include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include "../libft/libft.h"
# include "../minishell1.h"

// https://github.com/DimitriDaSilva/42_minishell


typedef struct d_list
{
	void			*content;
	struct d_list	*next;
	struct d_list	*previous;
}	t_dlist;

/*t_list *cmd_tables linked list with command tables (t_cmd_table *) as nodes*/

typedef struct s_ast
{
	t_list		*cmd_tables;
}	t_ast;

/*char *delimiter indicates what is separating this cmd table from the next potential values:
- delimiter = '\0' (last command table)
- delimiter = ";" (consecutive execution of the next cmd table)
- delimiter = "||" (execution of the next cmd table only if the previous has a falsy exit_status)
- delimiter = "&&" (execution of the next cmd table only if the previous has a truthy exit_status)

t_list *pids = linked list of pid. works as a queue / FIFO data structure. each time we
				fork(), we add a node at the back. We wait on dead child process as long as
				the queue is not empty.
int return_value = return value of this specific command table. We also have t_msh and exit_status
				field for that intent. But we need to make sure we don't ignore return value of builtin 
				functions like cd, if they finish first than forks like "sleep 5 | cd wrong_folder",
				cd would set error because wrong direction but sleep would execute correctly. So cd sets 
				the exit_status not sleep.*/

typedef struct s_cmd_table
{
	t_list		*cmds;
	char		*delimiter;
	int			nb_cmds;
	int			**pipes;
	t_list		*pids;
	int			return_value;
}	t_cmd_table;

/*A simple commandwith one program name and potentially one or more arguments examples: 
	ls -al dir
	echo "Hello, World!"
t_list *tokens = linked list with al the tokens of the simple command
	1st node : ls or (echo)
	2nd node : -al or (Hello, World!)
	3rd node : dir
*/

typedef struct s_cmd
{
	t_list	*tokens;
	t_list	*redirs;
}	t_cmd;

/*A single redirection targeting a simple command.
char type[2] = type of redirections.
	> = redirect stdout (for files, overwrite file's content)
	>> = redirect stdout (for files, append to file's content)
	<  = redirect stdin.*/

typedef struct s_redir
{
	char	*direction;
	char	type[2];
}	t_redir;

/*Settings of the terminal and a few capabilities from the termcaps lib.
*/

typedef struct s_termcaps
{
	struct termios	old_term; //default terminal setting i.e. canonical mode.
	struct termios	new_term; //modified terminal setting i.e. non-canonical node.
	char			*buffer; //the termcaps capabilities require a buffer to be passed to 
							//various functions like tgetent or tgetstr.
	char			*keys_on; // set keypad functionalities.
	char			*keys_off; // turn off keypad functionalities, required at end of programm
	char			*up_arrow; // value that terminal will return when pressing up arrrow.
	char			*down_arrow;
	char			*backspace;
	char			*del_line; // capability to delete the line where cursor is positioned
	char			*set_cursor_begin; //
}	t_termcaps;

//global struct that carries all data used throughout the program

typedef struct s_msh
{
	t_dlist		*input_history; //doubly link list, each node representing a prev. entered input
	t_ast		*ast; //struct with the abstract syntax tree.
	t_termcaps	termcaps; //settings of the termical and a few capabilities.
	t_list		*dup_envp; //duplicate of environment variables. each node is a string.
	int			exit_status; //exit status of the last simple command that ran.
	t_cmd_table	*curr_cmd_table; // points to the cmd_table being currently executed. This is useful
				// for when the exit program name is used alongside other simple commands we
				// don't have to exit, otherwise we do.
}	t_msh;

extern t_msh g_msh;

//errors.h
void	write_minishell_error(char *err_msg);
void	write_exec_error(char *exec_name, char *err_msg);
void	write_minishell_exec_error(char *exec_name, char *err_msg);
void	write_minishell_exec_arg_error(char *exec_name, char *arg, char *err_msg);
void	write_minishell_exec_arg_error_nocolon(char *exec_name, char *arg, char *err_msg);
int	cd_error_message(char *builtin, char *error);

//builtin_utils1.c
char	*replace_env_value(char **env_ptr, char *var_name, char *new_value);
void	update_environment_var(char *var, char *new_value, t_list *env);
int update_directories(char *old_dir, t_list **env);
int	is_token_valid_export (char *token_str, char *err_msg);
int	has_valid_identifier_export(char *token_str);


//builtin_utils2.c
int	has_only_one_cmd(void);
int	is_token_valid_unset(char *token_str, char *err_msg);
int	has_valid_identifier_unset(char *token_str);
void	ft_lstdel_node_nbr(t_list **lst, int node_nbr, void (*del)(void*));
ft_lstdel_middle(t_list **lst, int node_nbr, void (*del)(void*));

//ft_cd.c
int	only_cd_errors(t_list *tokens);
int	ft_cd(t_list *tokens, t_list **env);
int	execute_cd(t_list *tokens, t_list **env, char *pwd);
int	change_dir_home (char *cur_pwd, t_list **env);

//ft_cdutils.c
int	cd_error_message(char *builtin, char *error);
int	has_x_permission(char *path);
int	other_invalid_error(char *builtin, int error, char *arg);
int	cd_env_error_check(char *env);

//ft_export.c
void	create_environment_var(char *token_str, t_list **env);
t_list *get_sorted_env(t_list *env);
void	print_all_exported_vars (t_list *env);
void	update_env_var_with_token(char *token_str, char *var, t_list *env);
int	ft_export(t_list *tokens, t_list **env);

//ft_echo.c
int		has_repeated_char_in_str(char repeat_chr, char *str, unsigned int start);
int	ft_echo(t_list *tokens);


//ft_pwd.c
int	ft_pwd(void);

//ft_unset.h



#endif
