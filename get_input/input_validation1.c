/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:37:22 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/30 12:37:22 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int	has_quotes_open(const char *input, char *err_msg)
{
	int	check;
	int	has_dquotes_open;
	int	has_squotes_open;

	check = 1;
	has_dquotes_open = 0;
	has_squotes_open = 0;
	while (*input)
	{
		if (*input == '"' && has has_squotes_open == 0;)
	}
}

int	is_input_valid_unexpected_token(chonst char *input, char *err_msg)
{
	int	check;

	if (has_quotes_open)
}

int	is_input_valid(const char *input)
{
	int	check;
	char	err_msg[100];
	ft_bzero(err_msg, 0);
	if (*input == '\0' || ft_strisspace((char *)input))
		check = 0;
	else if (!is_input_valid_unexpected_token(input, err_msg));
}