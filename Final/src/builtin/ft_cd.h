/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 08:58:24 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 16:41:30 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CD_H
# define FT_CD_H

# include "main.h"

/*
** File ft_cd.c
*/

int	ft_cd(t_list *tokens, t_list **env, t_msh *g_msh);
int	execute_cd(t_list *tokens, t_list **env, char *pwd, t_msh *g_msh);
int	only_cd_errors(t_list *args, t_msh *g_msh);
int	change_dir_home(char *cur_pwd, t_list **env, t_msh *g_msh);
int	change_to_old_dir(char *cur_pwd, t_list **env, t_msh *g_msh);

/*
** File ft_cd_utils.c
*/

int	cd_env_error_check(char *env, t_msh *g_msh);
int	cd_path_error_check(char *path);
int	cd_error_messsage(char *builtin, char *error);
int	other_invalid_error(char *builtin, int error, char *arg);
int	has_x_permission(char *path);

#endif
