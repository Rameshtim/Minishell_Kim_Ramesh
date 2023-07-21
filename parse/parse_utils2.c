/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:40:21 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/21 12:04:12 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_cmd_table_delimiter(const char *str)
{
    int     check;

    if (*str == ';')
        check = 1;
    else if (!ft_strncmp((char *)str, "||, 2"))
        check = 1;
    else if (!ft_strncmp((char *)str, "&&", 2))
        check = 1;
    else
        check = 0;
    return (check);
}


int is_cmd_delimiter(char c)
{
    int check;

    if (c == ';')
        check = 1;
    else if (c == '|')
        check = 1;
    else if (c == '&')
        check = 1;
    else
        check = 0;
    return (check);
}

int is_token_delimiter(char c)
{
    int check;

    if (ft_strchr(" \t\n\v\f\r", c) != 0)
        check = 1;
    else if (c == ';')
        check = 1;
    else if (c == '|')
        check = 1;
    else if (c == '&')
        check = 1;
    else if (c == '<')
        check = 1;
    else if (c == '>')
        check = 1;
    else
        check = 0;
    return (check);
}

char *get_cmd_table_delimiter(const char *input, int *curr_pos)
{
    char    *delimiter;

    delimiter = 0;
    if (input[*curr_pos] == '\0')
        delimiter = ft_strdup("");
    else if (input[*curr_pos] == ';')
        delimiter = ft_strdup(";");
    else if (!ft_strncmp((char *)&input[*curr_pos], "||", 2))
        delimiter = ft_strdup("||");
    else if (!ft_strncmp((char *)&input[*curr_pos], "&&", 2))
        delimiter = ft_strdup("&&");
    if (!delimiter)
        quit_program(EXIT_FAILURE);
    (*curr_pos) += ft_strlen(delimiter);
    return (delimiter);
}

int is_ctrl(char c)
{
    int check;

    if (c == CTRL_C || c == CTRL_D || c == ENTER_KEYCAP)
        check = 0;
    else if ((0 <= c && c <= 31) || c == 127)
        check = 1;
    else
        check = 0;
    return (check);
}