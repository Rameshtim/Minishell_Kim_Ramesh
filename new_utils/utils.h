/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:36:03 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/27 12:17:25 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell1.h"

void	write_prompt(void);


//errors.h
void	write_minishell_error(char *err_msg);
void	write_exec_error(char *exec_name, char *err_msg);
void	write_minishell_exec_error(char *exec_name, char *err_msg);
void	write_minishell_exec_arg_error(char *exec_name, char *arg, char *err_msg);
void	write_minishell_exec_arg_error_nocolon(char *exec_name, char *arg, char *err_msg);
int	cd_error_message(char *builtin, char *error);

//init_minishell.c
void	init_minishell(t_msh *msh, char **envp);

//signals.c
void	catch_sigint(int signum);
void	catch_sigquit(int signum);

#endif