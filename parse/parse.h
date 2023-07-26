/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:57:21 by ramesh            #+#    #+#             */
/*   Updated: 2023/07/21 12:04:47 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include "../minishell1.h"

int is_cmd_table_delimiter(const char *str);
int is_cmd_delimiter(char c);
int is_token_delimiter(char c);
char *get_cmd_table_delimiter(const char *input, int *curr_pos);
int is_ctrl(char c);

//parse_utils1.c
void	skip_string_with_quotes(const char *input, int *curr_pos);
char	*ft_strstr_quotes(char *str, char *to_find);
void	skip_spaces(const char *input, int *curr_pos);
void	skip_letters(const char *input, int *curr_pos);
void	delete_quotes(char	*token);
			//to skip the i++;

#endif