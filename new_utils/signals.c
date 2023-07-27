/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:49:00 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/27 10:55:25 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	catch_sigint(int signum)
{
	//When user presses ctrl-c or ctrl-d a new line is added
	//as default signal interrupt behaviour
	(void)signum;
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	catch_sigquit(int signum)
{
	//print quit and kill children proceses.
	//if has default_signal sleep 5 | sleep 5; sleep 5 ctrl-\
	//would kill minishell.
	(void)signum;
	printf("Quit: 3\n");
	kill(0, SIGCHLD);
}