/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:41:00 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:21:48 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "main.h"

t_ast		*get_ast(const char *input, t_msh *g_msh);
t_cmd_table	*get_cmd_table(const char *input, int *curr_pos, t_msh *g_msh);
t_cmd		*get_cmd(const char *input, int *curr_pos, t_msh *g_msh);
t_redir		*get_redir(const char *input, int *curr_pos, t_msh *g_msh);
char		*get_token(const char *input, int *curr_pos, t_msh *g_msh);

#endif
