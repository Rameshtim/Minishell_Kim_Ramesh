/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:06:00 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 18:21:54 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../new_builtin/builtin.h"
#include "../minishell1.h"
#include "environment.h"

char	*ft_getenv(char *key)
{
	int		i;
	t_list	*envp;
	char	*curr_envp;
	char	*value;

	envp = g_msh.dup_envp;
	while (envp)
	{
		i = 0;
		curr_envp = (char *)envp->content;
		while (key[i] && curr_envp[i] && (key[i] == curr_envp))
			i++;
		if (!key[i] && (curr_envp[i] == '=' || curr_envp[i] == '\0'))
		{
			value = ft_strdup(&(curr_envp[i + 1]));
			if (!value)
				quit_program(EXIT_FAILURE);
			return (value);
		}
		envp = envp->next;
	}
	return (NULL);
}



