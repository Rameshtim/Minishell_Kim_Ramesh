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
	//the complement operator (~) inverts all the bits.
	//The AND operator (&) compares 2 bits. Sets bit to 1 only if both bits are equal to 1.
	termcaps->new_term = termcaps->old_term;
	//make a copy of a new_term in termcaps.
	termcaps->new_term.c_lflag &= ~ICANON;
	//disables the canonical mode by bitwise ANDing the c_lflag field.
	termcaps->new_term.c_lflag &= ~ECHO;
	//disable terminal echoing.
	termcaps->new_term.c_lflag &= ~ISIG;
	//disables signal generating characters(e.g Ctrl+C,Ctrl+D)
	termcaps->new_term.c_lflag &= ~IEXTEN;
	//disable implementation defined special character 
	termcaps->new_term.c_lflag &= ~IXON;
	//disable terminal input flow control
	termcaps->new_term.c_cc[VMIN] = 1;
	//VMIN specifies min. no. of character for read(). Setting to 1 ensures
	//read() returns as soon as a single character is available.
	termcaps->new_term.c_cc[VTIME] = 0;
	//VTIME is timeout for read(). Making it 0 means read() will not block and will
	//return immediately after reading specified character, our case 1.
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termcaps->new_term) == -1)
		quit_program(EXIT_FAILURE);
	//sets the terminal attributes for the stdin to specified value in new_term.
	//TCSANOW indicates the change should take effect immediately.
	//if tcsetarrt returns -1 exit the program.
}

int	ft_putint(int c)
{
	return (write(1, &c, 1));
}