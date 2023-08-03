/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:57:16 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/30 08:57:16 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int	is_up_down_arrow(char *buf, t_termcaps *termcaps)
{
	int	check;

	if (!ft_strcmp(termcaps->up_arrow, buf))
		check = 1;
	else if (!ft_strcmp(termcaps->down_arrow, buf))
		check = 1;
	else
		check = 0;
	return (check);
}

int	has_history(t_dlist *input_history, t_termcaps *termcaps, char *buf)
{
	//check if there is a history to show.
	int	check;

	if (!input_history)
		check = 0;
	else if (!ft_strcmp(termcaps->down_arrow, buf) && !input_history->previous)
		check = 0;
		//if down arrow pressed, check not at begining of list.
	else
		check = 1;
	return (check);
}

void	parse_input_history(t_dlist **input_history, t_termcaps *termcaps, char *buf, int *i)
{
	char	*input;

	if (!has_history(*input_history, termcaps, &buf[*i]))
	{
		ft_bzero(&buf[*i], BUFSIZ - *i);
		return ;
	}
	if (!ft_strcmp(termcaps->up_arrow, & buf[*i]) && !(*input_history)->next)
		input = (*input_history)->content;
		//up arrow + 1 node in list
	else if (!ft_strcmp(termcaps->up_arrow, &buf[*i]))
	{
		//up arrow + more than one node in list.
		input = (*input_history)->content;
		*input_history = (*input_history)->next;
	}
	else if (!ft_strcmp(termcaps->down_arrow, &buf[*i]))
	{
		//down arrow + more than one node in list.
		*input_history = (*input_history)->previous;
		input = (*input_history)->content;
	}
	tputs(termcaps->del_line, 1, ft_putint);
	//delete the current line from stdout
	tputs(termcaps->set_cursor_begin, 1, ft_putint);
	//bring cursor at begining.
	write_prompt();
	ft_bzero(buf, BUFSIZ);
	ft_strcpy(buf, input);
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
	//change the value of *i, so that the next char input will be set after
	//the input just wrote.
}

void	delete_single_char(t_termcaps *termcaps, char *buf, int *i)
{
	int	nb_char_to_delete;

	if (*i == 0 || ft_isascii(buf[*i - 1]))
		nb_char_to_delete = 1;
	else
		nb_char_to_delete = 2;
		//extended ASCII characters take 2 bytes.
	ft_bzero(&buf[*i - nb_char_to_delete], BUFSIZ - *i + nb_char_to_delete);
	//delete both the last char and backspace ANSI as well
	tputs(termcaps->del_line, 1, ft_putint);
	tputs(termcaps->set_cursor_begin, 1, ft_putint);
	write_prompt();
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
}

char	*get_input(t_dlist *input_history, t_termcaps *termcaps)
{
	char	*input;
	char	buf[BUFSIZ];
	//BUFSIZ is defined in stdio.h
	int		i;
	int		nb_char_read;

	i = 0;
	//index i is updated in parse_input_history(), in delete_single_char()
	//and by write();
	ft_bzero(buf, BUFSIZ);
	while (!ft_strchr(buf, '\n'))
	{
		nb_char_read = read(STDIN_FILENO, &buf[i], BUFSIZ - i);
		//since cannonical mode is off, meaning read() return after each keypress
		//regardless of the buffer_size. but for up_arrow in ANSI code 3 byte needed
		if (is_up_down_arrow(&buf[i], termcaps))
			parse_input_history(&input_history, termcaps, buf, &i);
		else if (!ft_strcmp&buf[i], termcaps->backspace)
			delete_single_char(termcaps, buf, &i);
			//since buf is previously set to NULL so the new value set in
			//buffer are NULL terminated.
		else if (nb_char_read > 2 || (nb_char_read == 1 && is_ctrl(buf[i])))
			ft_bzero(&buf[i], BUFSIZ - i);
		//if nb_char_read is greater than 2 bytes and is not arrow or backspace,
		//means special character and must not write in stdout immediately.
		else if (buf[i] == CTRL_C)
			reset_cmd_line(buf, &i, &input_history);
		else if (buf[i] == CTRL_D)
			exit_program(buf, i);
		else
			i += write(STDOUT_FILENO, &buf[i], nb_char_read);
			//since only one char has been read, we can safely write it to stdout and
			//increment i so that next char is read after the one just written.
	}
	input = extract_input(buf, i);
	return (input);
}

