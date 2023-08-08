/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:55:37 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:18:01 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "main.h"

void	init_termcaps(t_termcaps *termcaps, t_msh *g_msh);
int		has_capabilities(t_termcaps *termcaps);
void	turn_off_canonical_mode(t_termcaps *termcaps, t_msh *g_msh);
void	turn_on_canonical_mode(t_termcaps *termcaps, t_msh *g_msh);
int		ft_putint(int c);

#endif
