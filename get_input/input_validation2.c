/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:50:14 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/30 13:50:14 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int	has_char_at_end(const char *input, char c, char *err_msg)
{
	int		check;
	char	*cpy;
	int		len;

	cpy = ft_strtrim(input, " \t\n\v\f\r");
	if (!cpy)
		quit_program(EXIT_FAILURE);
	len = ft_strlen(cpy);
	if (cpy[len - 1] == c)
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

int	has_forbidden_sequence(const char *input, char *test, char *err_msg)
{
	//check for syntax errors or non supported feature like "&&"
	int		check;
	char	*trimmed;

	trimmed = ft_strtrim_all(input, " \t\n\v\f\r");
	if (!trimmed)
		quit_program(EXIT_FAILURE);
	if (ft_strstr_quotes(trimmed, test) != 0)
	{
		//it will not look between quotes but
		//if strstr_quotes returns the address, it means that input has syntax error.
		check = 1;
		ft_strcpy(err_msg, "syntax error near unexpected token `");
		ft_strlcat(err_msg, test, 1);
		ft_strcat(err_msg, "'");
	}
	else
		check = 0;
	free(trimmed);
	return (check);
}

int	has_spaces_between_char(const char *input, char c, char *err_msg)
{
	//checks if a character is found twice with only spaces between them.
	// "test | test" is ok but "test |	| test" not ok.
	// "test > log.txt" and "test >> log.txt" ok but "test >	> log.txt" not ok
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			skip_string_with_quotes(input, &i);
		if (input[i] == c && input[i + 1] == ' ')
		{
			i++;
			skip_spaces((char *)input, &i);
			if (input[i] == c)
			{
				ft_strcpy(err_msg, "syntax error near unexpected token `");
				ft_strlcat(err_msg, &c, 1);
				ft_strcat(err_msg, "'");
				return (1);
			}
		}
		if (input[i])
			i++;
	}
	return (0);
}

int	has_non_supported(const char *input, char *test, char *err_msg)
{
	int	check;
	
	if (ft_strstr_quotes((char *)input, test) != 0)
	{
		check = 1;
		ft_strcpy(err_msg, "\"");
		ft_strcat(err_msg, test);
		ft_strcat(err_msg, "\" not supported");
	}
	else
		check = 0;
	return (check);
}

int	has_non_supported_one(const char *input, char *test, char *err_msg)
{
	//like "echo && test" is ok but "echo & test" not ok
	int		check;
	char	*tmp;

	check = 0;
	tmp = (char *)input;
	while (tmp)
	{
		tmp = ft_strstr_quotes(tmp, test);
		if (tmp != 0 && *(tmp + 1) != *test)
		{
			check = 1;
			break ;
		}
		else if (tmp != 0 && *(tmp + 1) == *test)
			tmp += 2;
	}
	if (check)
	{
		ft_strcpy(err_msg, "\"");
		ft_strcat(err_msg, test);
		ft_strcat(err_msg, "\" not supported");
	}
	return (check);
}