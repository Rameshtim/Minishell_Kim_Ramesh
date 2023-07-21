/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:40:02 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 12:03:59 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"

# define CTRL_D 4
# define CTRL_C 3
# define ENTER_KEYCAP 10
# define CTRL_B 28

# define EXIT_GENERAL_ERROR 2
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CMD_INTERRUPTED 130
# define EXIT_ERROR_FORMAT 258

#include "new_builtin/builtin.h"
#include "new_env/environment.h"
#include "quit_free/quit_free.h"
#include "parse/parse.h"
#include "quit_programm/free_memory.h"
#include "get_input/termcaps.h"

#endif