/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:33:16 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/18 15:54:10 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_list	*add_list_env(char **env)
{
	t_list	*head;
	char	*str;
	int		i;

	head = create_list(env[0]);
	i = 0;
	while (env[++i])
	{
		str = ft_strdup(env[i]);
		head = list_add_back(head, str);
	}
	return (head);
}
