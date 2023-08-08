/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:38:08 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/08 13:56:35 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_prompt.h"

/*
** Displays the prompt to the user
** Line-by-line comments:
** @1-4		Color of the prompt will the depend on the last exit_status
** @6		Set back the color to white
*/

void	write_prompt(void)
{
	ft_putstr_fd("minishell: ", 1);
}
