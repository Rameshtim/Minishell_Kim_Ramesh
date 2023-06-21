/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:56 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/14 17:12:41 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	is_env_var(char *potential_var, t_list *env)
{
	int	i;
	char	*env_str;

	while (env)
	{
		i = 0;
		env_str = (char *)env->content;
		while (potential_var[i] && env_str[i] && (potential_var[i] == env_str[i]))
			i++;
		if ((potential_var[i] == 0 || ft_isspace(potential_var[i])) && (env_str[i] == '=' || env_str[i] == '\0'))
			return (1);
		env = env->next; 
	}
	return (0);
}