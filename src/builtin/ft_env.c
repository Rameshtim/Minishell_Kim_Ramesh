/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:52:27 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 09:52:28 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

int	ft_env(t_list *env, t_msh *g_msh)
{
	char	*env_str;

	printf("%s\n", "8.3.5.7.4.0.ft_env");
	save_last_token(g_msh->curr_cmd_table, g_msh);
	printf("%s\n", "8.3.5.7.4.1.ft_env");
	while (env)
	{
		printf("%s\n", "8.3.5.7.4.2.ft_env");
		env_str = (char *)env->data;
		printf("%s\n", "8.3.5.7.4.3.ft_env");
		if (ft_strchr(env_str, '='))
		{
			printf("%s\n", "8.3.5.7.4.4.ft_env");
			printf("%s\n", env_str);
		}
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
