/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:06:35 by dda-silv          #+#    #+#             */
/*   Updated: 2023/08/03 17:23:55 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H

# include "main.h"

/*
** File input_validation1.c
*/

int	is_input_valid(const char *input, t_msh *g_msh);
int	is_input_valid_unexpected_token(const char *input, char *err_message, t_msh *g_msh);
int	is_input_valid_not_supported(const char *input, char *err_message);
int	has_quotes_open(const char *input, char *error_message);
int	has_char_at_beginning(const char *input, char c, char *error_message, t_msh *g_msh);

/*
** File input_validation2.c
*/

int	has_char_at_end(const char *input, char c, char *error_message, t_msh *g_msh);
int	has_forbidden_sequence(const char *input, char *test, char *error_message, t_msh *g_msh);
int	has_spaces_between_char(const char *input, char c, char *error_message);
int	has_non_supported(const char *input, char *test, char *error_message);
int	has_non_supported_one(const char *input, char *test, char *err_message);

#endif
