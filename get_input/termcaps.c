/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:33:46 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 16:33:46 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	turn_on_canonical_mode(t_termcaps *termcaps)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termcaps->old_term) == -1)
		quit_program(EXIT_FAILURE);
}

void	turn_off_canonical_mode(t_termcaps *termcaps)
{
	termcaps->new_term = termcaps->old_term;
	termcaps->new_term.c_lflag &= ~ICANON;
}

int	ft_putint(int c)
{
	return (write(1, &c, 1));
}