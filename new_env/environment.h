/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:59:12 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 12:27:03 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "../new_builtin/builtin.h"
#include "../minishell1.h"


//env_utils1.c
int	is_env_var(char *potential_var, t_list *env);
char	*get_var_name(char *str);
int	ft_strnstr_iterator(char *haystack, char *needle, size_t len);
char	*replace_midstring(char *original, char *old_substr, char *new_substr, int replace_i);
void	tilde_join(char **str, char **home_path);


//env2.c
char	*ft_getenv(char *key);
void	duplicate_env(t_list **dup_envp, char **envp);
void	remove_env_value(char *key);
void	replace_status_env(char **str, int last_status);
int	is_path_executable(cahr *exec_file);

//env3.c
t_list	*get_split_token(char *token);
int	get_new_token_size(t_list *split_token);
char	*join_split_token(t_list *split_token);
void	replace_one_var(char **str);



//get_absolute_path.c
void	add_slash(char ***path_env_split);
void	free_arr(void **ptr);
char	**get_path_env_split(void);
char	*get_correct_path(char *program_name, char **path_env_split);
char	*get_absolute_path(char *program_name);

//save_last_token.c
void	*ft_lst_get_data_last_node(t_list *lst);
int	has_relative_path(char *first_token);
char	*convert_to_path(char *token);
void	save_last_token(t_cmd_table *cmd_table);

//env_utils2.c
char	*get_value_name(char *str);
int	is_token_empty(void *data);
void	replace_string(char *src, char **dest);


#endif