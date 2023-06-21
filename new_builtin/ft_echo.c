/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:20:17 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 15:27:31 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int		has_repeated_char_in_str(char repeat_chr, char *str, unsigned int start)
{
	unsigned int	i;

	i = start;
	while (str[i])
	{
		if (str[i] != repeat_chr)
			return (0);
		i++;	
	}
	return (1);
}

int	ft_echo(t_list *tokens)
{
	int	line_break;
	int	flag_time;
	char	*arg;

	//-n will supress new_line /n so the cursor will not move to new line
	//echo hello
	//hello
	//$
	//echo -n hello
	//hello$
	flag_time = 1;
	//we use only one flag -n
	line_break = 1;
	//if -n is not used cursor moves to new line
	while (tokens)
	{
		arg = tokens->content;
		//arg[0] == '-n' will check for simple flag echo -n
		if (flag_time && arg[0] == '-' && has_reapeted_char_in_str('n', arg, 1))
			line_break = 0;
		else
		{
			if (!flag_time)
				ft_putchar_fd(' ', STDOUT_FILENO);
			flag_time = 0;
			ft_putstr_fd(arg, STDOUT_FILENO);
		}
		tokens = tokens->next;
	}
	if (line_break)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}