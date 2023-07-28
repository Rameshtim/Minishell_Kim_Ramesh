/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:44:02 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 19:00:37 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_exit(t_list *args)
{
	if (has_only_one_cmd())
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (args == 0 && has_only_one_cmd())
		quit_program(g_msh.exit_status);
	else if (args == 0 && !has_only_one_cmd())
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}