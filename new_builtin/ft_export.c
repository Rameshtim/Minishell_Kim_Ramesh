/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:37:20 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/14 17:14:16 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	create_environment_var(char *token_str, t_list **env)
{
	t_list	*new_var;
	char	*new_var_str;

	new_var_str = ft_strdup(token_str);
	if (new_var_str == 0)
		quit_programm(EXIT_FAILURE);
	new_var = ft_lstnew(new_var_str);
	if (new_var == 0)
		quit_programm(EXIT_FAILURE);
	ft_lstadd_front(env, new_var);
}