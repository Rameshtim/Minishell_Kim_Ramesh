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

#endif