/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:31:19 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/27 12:39:52 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "../minishell1.h"

//termcaps.c
void	turn_on_canonical_mode(t_termcaps *termcaps);
void	turn_off_canonical_mode(t_termcaps *termcaps);
int	ft_putint(int c);
void	init_termcaps(t_termcaps *termcaps);
int	has_capabilities(t_termcaps *termcaps);

//get_input2.c
void	reset_cmd_line(char *buf, int *i, t_dlist **input_history);
void	exit_program(char *buf, int i);
char	*extract_input(char *buf, int i);

//get_input1.c
int	is_up_down_arrow(char *buf, t_termcaps *termcaps);
int	has_history(t_dlist *input_history, t_termcaps *termcaps, char *buf);
void	parse_input_history(t_dlist **input_history, t_termcaps *termcaps, char *buf, int *i);
void	delete_single_char(t_termcaps *termcaps, char *buf, int *i);
char	*get_input(t_dlist *input_history, t_termcaps *termcaps);
#endif