/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:02:51 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/30 12:02:51 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	reset_cmd_line(char *buf, int *i, t_dlist **input_history)
{
	write(STDOUT_FILENO, "^C\n", ft_strlen("^C\n"));
	g_msh.exit_status = EXIT_CMD_INTERRUPTED;
	write_prompt();
	ft_bzero(buf, BUFSIZ);
	*i = 0;
	if (*input_history)
	{
		while ((*input_history)->previous)
			*input_history = (*input_history)->previous;
		//after ctrl-c need to rewind the input history.
	}
}

void	exit_program(char *buf, int i)
{
	//ctrl-d only exists if cmd line is empty
	if (i > 0)
	{
		//need to overwrite the end of transmission character from the buffer
		//if we don't exit.
		buf[i] = '\0';
		return ;
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	quit_program(g_msh.exit_status);
}

char	*extract_input(char *buf, int i)
{
	char	*input;

	buf[i - 1] = '\0';
	input = ft_strdup(buf);
	if (!input)
		quit_program(EXIT_FAILURE);
	return (input);
}