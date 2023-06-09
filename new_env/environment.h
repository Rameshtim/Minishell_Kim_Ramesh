/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:59:12 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 17:59:09 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "../new_builtin/builtin.h"
#include "../minishell1.h"


//env_utils1.c
int	is_env_var(char *potential_var, t_list *env);


//env2.c
char	*ft_getenv(char *key);


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


#endif