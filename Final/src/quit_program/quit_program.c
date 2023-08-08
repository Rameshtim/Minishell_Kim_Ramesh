/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:07:39 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:18:13 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit_program.h"

/*
** Exits the program by doing some cleaning before
** @param:	- [int] exit_code, like EXIT_SUCCESS or EXIT_FAILURE
** Line-by-line comments:
** @4-5		When "ks" termcap is used, we need to turn it off before exiting
** @6		In this program we have tweaked the terminal default settings so
**			we need to make sure they are as they were when the program started
*/

void	quit_program(int exit_code, t_msh *g_msh)
{
	t_termcaps	*termcaps;

	termcaps = &g_msh->termcaps;
	if (termcaps->keys_off)
		tputs(termcaps->keys_off, 1, ft_putint);
	turn_on_canonical_mode(termcaps, g_msh);
	free_msh(g_msh);
	exit(exit_code);
}
