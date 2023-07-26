/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:16:36 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/23 11:16:36 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	skip_string_with_quotes(const char *input, int *curr_pos)
{
	//find the starting of single / double quotes, then keeps incrementing
	// *curr_pos till the closing quote.
	//don't care about double quotes if single quotes are open because
	//it will be part of the token enclosed by the single quotes.
	int	has_double_quotes_open;
	int	has_single_quotes_open;

	has_double_quotes_open = 0;
	has_single_quotes_open = 0;
	while (input[*curr_pos])
	{
		if (input[*curr_pos] == '"' && has_single_quotes_open == 0)
			has_double_quotes_open = !has_double_quotes_open;
		//if ture, here 0 becomes 1 and 1 becomes 0
		else if (input[*curr_pos] == '\'' && has_double_quotes_open == 0)
			has_single_quotes_open = !has_single_quotes_open;
		(*curr_pos)++;
		if (!has_double_quotes_open && !has_single_quotes_open)
			break ;
	}
}

char	*ft_strstr_quotes(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!(*to_find))
		return (str);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			skip_string_with_quotes(str, &i);
		if (!ft_strcmp(&str[i], to_find, ft_strlen(to_find)))
			return (&str[i]);
		if (str[i])
			i++;
		//skip_string_with_quotes can reach end of string so increment
		//so check for str[i] before incrementing i;
	}
	return (0);
}

void	skip_spaces(const char *input, int *curr_pos)
{
	while (input[*curr_pos] && ft_isspace(input[*curr_pos]))
		(*curr_pos)++;
}

void	skip_letters(const char *input, int *curr_pos)
{
	//considers $PATH in $PATH$TERM as it's own string
	if (input[*curr_pos] == '$' || input[*curr_pos] == '/')
		(*curr_pos)++;
	while (input[*curr_pos] && !is_quote(input[*curr_pos]) \
		&& input[*curr_pos] != '$' && input[*curr_pos] != '/')
		(*curr_pos)++;
}

void	delete_quotes(char	*token)
{
	//to delete unnecessary quotes.
	int	i;
	int	has_double_quotes_open;
	int	has_singel_quotes_open;

	i = 0;
	has_double_quotes_open = 0;
	has_singel_quotes_open = 0;
	while (token[i])
	{
		if (token[i] == '"' && has_singel_quotes_open == 0)
		{
			has_double_quotes_open = !has_double_quotes_open;
			ft_strcpy(&token[i], (const char *)&token[i + 1]);
			continue ;
			//to skip the i++;
		}
		else if (token[i] == '\'' && has_double_quotes_open = 0)
		{
			has_singel_quotes_open = !has_singel_quotes_open;
			ft_strcpy(&token[i], (const char *)&token[i + 1]);
			continue ;
		}
		i++;
	}
}