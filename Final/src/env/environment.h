/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:59:16 by gleal             #+#    #+#             */
/*   Updated: 2023/08/03 17:12:39 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "main.h"

/*
** File environment1.c
*/

void	replace_envs(t_list **tokens, t_list *redirs, t_msh *g_msh);
void	replace_env_single_token(char **token, t_msh *g_msh);
void	replace_vars_with_values(char **str, t_msh *g_msh);
void	replace_tilde_with_home(char **token, t_msh *g_msh);
char	*get_last_exec_name(char *env_var, t_msh *g_msh);

/*
** File environment2.c
*/

char	*ft_getenv(char *key, t_msh *g_msh);
void	duplicate_env(t_list **dup_envp, char **envp, t_msh *g_msh);
void	remove_env_value(char	*key, t_msh *g_msh);
void	replace_status_env(char **str, int	last_status, t_msh *g_msh);
int		is_path_executable(char *exec_file);

/*
** File environment3.c
*/

t_list	*get_split_token(char *token, t_msh *g_msh);
char	*join_split_token(t_list *split_token, t_msh *g_msh);
int		get_new_token_size(t_list *split_token);
void	replace_one_var(char **str, t_msh *g_msh);

/*
** File save_last_token.c
*/

void	save_last_token(t_cmd_table *cmd_table, t_msh *g_msh);
char	*convert_to_path(char *token, t_msh *g_msh);

#endif