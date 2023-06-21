/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:29:31 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 18:33:47 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(t_list *env)
{
	char	*env_str;

	save_last_token(g_msh.curr_cmd_table);
	while (env)
	{
		env_str = (char *)env->content;
		if (ft_strchr(env_str, '='))
			printf("%s\n", env_str);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}