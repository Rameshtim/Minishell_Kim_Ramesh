/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:47:12 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:13:13 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ABSOLUTE_PATH_H
# define GET_ABSOLUTE_PATH_H

# include "main.h"

char	*get_absolute_path(char *program_name, t_msh *g_msh);
char	**get_path_env_split(t_msh *g_msh);
char	*get_correct_path(char *program_name, char **path_env_split, t_msh *g_msh);
void	add_slash(char ***path_env_split);

#endif
