/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:39:11 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/11 14:39:12 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//const char is a mutable(changable) pointer 
//to an immutable(unchangable) character/string
//compares two character strings (s1 and s2)
//(!p1) is same as (p1 == 0)

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
    const char s1[] = "12345";
    const char s2[] = "12344";

    int compare1 = ft_strncmp(s1, s2, 0);
    int compare2 = ft_strncmp(s1, s2, 4);
    int compare3 = ft_strncmp(s1, s2, 5);
    int compare4 = ft_strncmp(s1, s2, 6);

    printf("Result1: %d\n", compare1);
    printf("Result2: %d\n", compare2);
    printf("Result3: %d\n", compare3);
    printf("Result4: %d\n", compare4);
    return (0);
}*/
