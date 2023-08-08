/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:11:21 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:26:17 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

# include "main.h"

/*
** File builtins_utils1.c
*/

int		update_directories(char *old_dir, t_list **env, t_msh *g_msh);
void	update_environment_var(char *var, char *new_value, t_list *env, t_msh *g_msh);
char	*replace_env_value(char **env_ptr, char	*var_name, char *new_value, t_msh *g_msh);

int		has_valid_identifier_export(char *token_str);
int		is_token_valid_export(char *token_str, char *err_message);

/*
** File builtins_utils2.c
*/

int		has_valid_identifier_unset(char *token_str);
int		is_token_valid_unset(char *token_str, char *err_message);
void	ft_lstdel_node_nbr(t_list **lst,
			int node_nbr,
			void (*del)(void *));
void	ft_lstdel_middle(t_list **lst,
			int node_nbr,
			void (*del)(void*));
int		has_only_one_cmd(t_msh *g_msh);

#endif
