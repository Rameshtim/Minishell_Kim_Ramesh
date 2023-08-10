/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:16:51 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/06 17:51:22 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	char	*str;
	char	*src;

	str = s1;
	src = s2;
	while (*str == *src && *str)
	{
		str++;
		src++;
	}
	return (*str - *src);	
}
