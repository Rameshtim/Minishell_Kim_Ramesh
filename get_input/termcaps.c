/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:33:46 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/27 12:38:44 by rtimsina         ###   ########.fr       */
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

void	init_termcaps(t_termcaps *termcaps)
{
	//initiate termcaps setting to use terminal capabilities.
	char	*term_type;

	//get terminal setting
	if (tcgetattr(STDIN_FILENO, &termcaps->old_term) == -1)
		quit_program(EXIT_FAILURE);
	term_type = ft_getenv("TERM");
	if (!term_type)
		quit_program(EXIT_FAILURE);
	if (tgetent(termcaps->buffer, term_type) <= 0)
		quit_program(EXIT_FAILURE);
	else if (!has_capabilities(termcaps))
		quit_program(EXIT_FAILURE);
	free(term_type);
}

int	has_capabilities(t_termcaps *termcaps)
{
	int	check;
	
	termcaps->keys_on = tgetstr("ks", &termcaps->buffer);
	//"ks-keystart" enables the terminal to return ANSI code when special keys 
	//are pressed like up_arrow
	if (termcaps->keys_on)
		tputs(termcaps->keys_on, 1, ft_putint);
	termcaps->keys_off = tgetstr("ke", &termcaps->buffer);
	//if "ks" is used "ke-keyend" must be used at the end of the programm.
	termcaps->up_arrow = tgetstr("ku", &termcaps->buffer);
	//Function keys aren't like common capabilities.To use tputs is not needed.
	//we compare the values read by the buffer when pressing to up arrow
	//to the return value of "ku-keys up"
	termcaps->down_arrow = tgetstr("kd", &termcaps->buffer);
	termcaps->backspace = tgetstr("kb", &termcaps->buffer);
	termcaps->del_line = tgetstr("dl", &termcaps->buffer);
	termcaps->set_cursor_begin = tgetstr("cr", &termcaps->buffer);
	if (!termcaps->keys_off || termcaps->keys_on || termcaps->up_arrow \
		|| termcaps->down_arrow || termcaps->backspace || \
		termcaps->del_line || termcaps->set_cursor_begin)
		check = 0;
	else
		check = 1;
	return (check);
}