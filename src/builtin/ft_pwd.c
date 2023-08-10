/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:53:40 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 09:53:41 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pwd.h"

int	ft_pwd(void)
{
	char	pwd[MAX_PATH];

	printf("%s\n", "8.3.5.7.6.0.hello");
	if (getcwd(pwd, MAX_PATH) == NULL)
	{
		printf("%s\n", "8.3.5.7.6.2.hello");
		return (EXIT_FAILURE);
	}
	printf("%s\n", "8.3.5.7.6.3.hello");
	printf("%s\n", pwd);
	printf("%s\n", "8.3.5.7.6.4.hello");
	return (EXIT_SUCCESS);
}