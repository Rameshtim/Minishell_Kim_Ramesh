/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:58:12 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/24 16:01:39 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_perror(char *msg, char *utils)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (utils)
		write(STDERR_FILENO, utils, ft_strlen(utils));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}