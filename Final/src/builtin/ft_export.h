/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:06:00 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:23:38 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPORT_H
# define FT_EXPORT_H

# include "main.h"

int		ft_export(t_list *tokens, t_list **env, t_msh *g_msh);
void	print_all_exported_vars(t_list *env, t_msh *g_msh);
void	update_env_var_with_token(char *token_str, char *var, 
t_list *env, t_msh *g_msh);
void	create_environment_var(char *token_str, t_list **env, t_msh *g_msh);
t_list	*get_sorted_env(t_list *env, t_msh *g_msh);

#endif
