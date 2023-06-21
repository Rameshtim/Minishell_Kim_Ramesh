/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:51:21 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/01 11:51:21 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	write_minishell_error(char *err_msg)
{
	ft_putstr_fd ("minishell: ", STDERR_FILENO);
	ft_putstr_fd (err_msg, STDERR_FILENO);
	ft_putstr_fd ("\n", STDERR_FILENO);
}

void	write_exec_error(char *exec_name, char *err_msg)
{
	ft_putstr_fd (exec_name, STDERR_FILENO);
	ft_putstr_fd (": ", STDERR_FILENO);
	ft_putstr_fd (err_msg, STDERR_FILENO);
	ft_putstr_fd ("\n", STDERR_FILENO);
}

void	write_minishell_exec_error(char *exec_name, char *err_msg)
{
	ft_putstr_fd ("minishell: ", STDERR_FILENO);
	ft_putstr_fd (exec_name, STDERR_FILENO);
	ft_putstr_fd (": ", STDERR_FILENO);
	ft_putstr_fd (err_msg, STDERR_FILENO);
	ft_putstr_fd ("\n", STDERR_FILENO);
}

void	write_minishell_exec_arg_error(char *exec_name, char *arg, char *err_msg)
{
	ft_putstr_fd ("minishell: ", STDERR_FILENO);
	ft_putstr_fd (exec_name, STDERR_FILENO);
	ft_putstr_fd (": ", STDERR_FILENO);
	ft_putstr_fd (arg, STDERR_FILENO);
	ft_putstr_fd (": ", STDERR_FILENO);
	ft_putstr_fd (err_msg, STDERR_FILENO);
	ft_putstr_fd ("\n", STDERR_FILENO);
}

void	write_minishell_exec_arg_error_nocolon(char *exec_name, char *arg, char *err_msg)
{
	ft_putstr_fd ("minishell: ", STDERR_FILENO);
	ft_putstr_fd (exec_name, STDERR_FILENO);
	ft_putstr_fd (": ", STDERR_FILENO);
	ft_putstr_fd (arg, STDERR_FILENO);
	ft_putstr_fd (err_msg, STDERR_FILENO);
	ft_putstr_fd ("\n", STDERR_FILENO);
}
