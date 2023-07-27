/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:45:28 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/27 12:16:31 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_minishell(t_msh *msh, char **envp)
{
	if (!isatty(STDIN_FILENO))
		quit_program(EXIT_FAILURE);
	//Make sure terminal is linked to STDIN
	ft_bzero(msh, sizeof(t_msh));
	duplicate_env(&msh->dup_envp, envp);
	unset_oldpwd();
	increment_shlvl();
	init_termcaps(&msh->termcaps);
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
}