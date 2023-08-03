/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:07:11 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 16:26:13 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNSET_H
# define FT_UNSET_H

# include "main.h"

int		ft_unset(t_list *tokens, t_list **env, t_msh *g_msh);
void	delete_env_var(char *var, t_list **env);
void	ft_delete_list_str(void *data);

#endif
