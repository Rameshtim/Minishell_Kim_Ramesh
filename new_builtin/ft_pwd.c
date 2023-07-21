/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:34:57 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/21 12:37:45 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	char	pwd[MAX_PATH];

	if (getcwd(pwd, MAX_PATH) == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", pwd);
	return (EXIT_SUCCESS);
}