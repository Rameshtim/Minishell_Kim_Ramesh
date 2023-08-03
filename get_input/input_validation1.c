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
	//open quotes eg
	// > "   	> " '		>" ' " '
	//not open quotes
	// > " "	>" ' "		> " ' ' "
	int	check;
	int	has_dquotes_open;
	int	has_squotes_open;

	check = 1;
	has_dquotes_open = 0;
	has_squotes_open = 0;
	while (*input)
	{
		if (*input == '"' && has has_squotes_open == 0;)
			has_dquotes_open = !has_dquotes_open;
		else if (*input == '\'' && has_dquotes_open == 0)
			has_squotes_open = !has_squotes_open;
		input++;
	}
	if (has_dquotes_open || has_squotes_open)
	{
		check = 1;
		ft_strcpy(err_msg, "syntax error: open quotes");
	}
	else
		check = 0;
	return (check);
}

int	has_char_at_beginning(const char *input, char c, char *err_msg)
{
	int		check;
	char	*cpy;

	cpy = ft_strtrim(input, " \t\n\v\f\r");
	//we need to trim white space from the input while not changing initial input
	if (!cpy)
		quit_program(EXIT_FAILURE);
	if (cpy[0] == c)
	{
		check = 1;
		ft_strcpy(err_msg, "syntax error near unexpected token `");
		ft_strlcat(err_msg, &c, 1);
		ft_strlcat(err_msg, "'", 2);
	}
	else
		check = 0;
	free(cpy);
	return (check);
}

int	is_input_valid_not_supported(const char *input, char *err_msg)
{
	int		check;

	if (has_non_supported(input, "*", err_msg) || has_non_supported(input, "\\", err_msg) \
		has_non_supported_one(input, "&", err_msg))
		check = 0;
	else
		check = 1;
	return (check);
}

int	is_input_valid_unexpected_token(chonst char *input, char *err_msg)
{
	int	check;

	if (has_quotes_open(input, err_msg) || has_char_at_beginning(input, '|', err_msg) \
		|| has_char_at_beginning(input, ';', err_msg) || has_char_at_end(input, '|', err_msg) \
		|| has_char_at_end(input, '<', err_msg) || has_char_at_end(input, '>', err_msg) \
		|| has_char_at_end(input, '&', err_msg) || has_forbidden_sequence(input, ";;", err_msg) \
		|| has_forbidden_sequence(input, "|;", err_msg) || has_forbidden_sequence(input, "&;", err_msg) \
		|| has_forbidden_sequence(input, ";|", err_msg) || has_forbidden_sequence(input, ";&", err_msg) \
		|| has_forbidden_sequence(input, ">>>", err_msg) || has_spaces_between_char(input, '|', err_msg) \
		|| has_spaces_between_char(input, '>', err_msg))
		check = 0;
	else
		check = 1;
	return (check);
}

int	is_input_valid(const char *input)
{
	int	check;
	char	err_msg[100];
	ft_bzero(err_msg, 0);
	if (*input == '\0' || ft_strisspace((char *)input))
		check = 0;
	else if (!is_input_valid_unexpected_token(input, err_msg) || !is_input_valid_not_supported(input, err_msg))
	{
		check = 0;
		g_msh.exit_status = ENOEXEC;
		write_minishell_error(err_msg);
	}
	else
		check = 1;
	return (check);
}