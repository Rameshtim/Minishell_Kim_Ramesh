/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:00:54 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/20 16:14:23 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

char	*ft_strcpy(char	*dest, const char *src)
{
	if (!src)
		return ;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*str;

	str = dest;
	if (!src)
		return ;
	while (*str)
		str++;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str);
}