/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:04:57 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/18 09:44:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_PIPES_2_H
# define REDIRECTIONS_PIPES_2_H

# include "main.h"

int	open_heredoc_file(t_redir *redir, int prev_fd, int flags, mode_t permissions, t_msh *g_msh);
void read_heredoc_file(t_redir *redir, t_msh *g_msh);

#endif