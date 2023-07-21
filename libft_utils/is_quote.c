/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:11:49 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/21 12:12:52 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int is_quote(char c)
{
	int	check;

	if (c == '"' || c == '\'')
		check = 1;
	else
		check = 0;
	return (check);
}