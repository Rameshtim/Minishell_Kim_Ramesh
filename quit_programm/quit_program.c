/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:27:40 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/27 10:47:03 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_memory.h"

void	quit_program(int exit_code)
{
	t_termcaps	*termcaps;

	termcaps = &g_msh.termcaps;
	if (termcaps->keys_off)
		tputs(termcaps->keys_off, 1, ft_putint);
	turn_on_canonical_mode(termcaps);
	free_msh(&g_msh);
	exit(exit_code);
}
