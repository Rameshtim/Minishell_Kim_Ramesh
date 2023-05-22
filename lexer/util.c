/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:05:18 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/18 10:05:19 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lexer.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
} 

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*newstr;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (start <= i && j < len)
		{
			newstr[j] = str[i];
			j++;
		}
		i++;
	}
	newstr[j] = '\0';
	return (newstr);
}
