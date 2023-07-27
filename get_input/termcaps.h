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
#define TERMCAPS_H

# include "../minishell1.h"

//termcaps.c
void	turn_on_canonical_mode(t_termcaps *termcaps);
void	turn_off_canonical_mode(t_termcaps *termcaps);
int	ft_putint(int c);
void	init_termcaps(t_termcaps *termcaps);
int	has_capabilities(t_termcaps *termcaps);

#endif