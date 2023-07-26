/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:22:58 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/25 20:22:58 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	has_absolute_path(char *first_token)
{
	if (*first_token == '/')
		return (1);
	return (0);
}