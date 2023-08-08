/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:58:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/17 19:01:51by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_minishell.h"

/*
** Set a few things the program needs to run
** @param:	- [t_msh *] main struct of the program
**			- [char **] environment pointers that we need to duplicate
** Line-by-line comments:
** @1-2		Makes sure that the terminal is linked to the STDIN
** @6		Increases SHLVL environment variable everytime we call 
** 			./minishell inside another one
*/

void	init_minishell(char **envp, t_msh *g_msh)
{
	// printf("%s\n", "00.0.init_minishell");
	if (!isatty(STDIN_FILENO))
	{
		// printf("%s\n", "01.1.init_minishell");
		quit_program(EXIT_FAILURE, g_msh);
	}
	// printf("%s\n", "01.2.init_minishell");
	ft_bzero(g_msh, sizeof(t_msh));
	// printf("%s\n", "01.3.init_minishell");
	duplicate_env(&g_msh->dup_envp, envp, g_msh);
	// printf("%s\n", "01.4.init_minishell");
	unset_oldpwd(g_msh);
	// printf("%s\n", "01.5.init_minishell");
	increment_shlvl(g_msh);
	// printf("%s\n", "01.6.init_minishell");
	init_termcaps(&g_msh->termcaps, g_msh);
	// printf("%s\n", "01.7.init_minishell");
	signal(SIGINT, catch_sigint);
	// printf("%s\n", "01.8.init_minishell");
	signal(SIGQUIT, catch_sigquit);
	// printf("%s\n", "01.9.init_minishell");
}
