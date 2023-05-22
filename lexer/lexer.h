/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:24:12 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/17 07:24:13 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
#include <readline/history.h>
//# include "../../libft/libft.h"

# define DIED "DIED"




enum e_token
{
	WORD,
	S_QUOTE,
	D_QUOTE,
	SPACE_,
	DOLLER,//
	PIPE,
	NEW_LINE,
	REDIRECT_IN,//<
	REDIRECT_OUT,//>
	ESC_,
	HEREDOC,//<<
	APPMODE,//>>
};

enum e_state
{
	OTHER,
	IN_SQUOTE,
	IN_DQUOTE,
};

typedef struct s_list
{
	char *input;
	int	len;
	enum e_token type;
	enum e_state state;
	struct s_list *next;
}	t_list;

typedef struct s_parse
{
    char 	**command;
    int 	size;
    int	redirection_in;
    int	redirection_out;
    char *infilepath;  //if redirection_in == 0, infilepath = NULL
    char *outfilepath; //if redirection_out == 0, outfilepath = NULL
    int pipe;
    int	fd[2];   //if pipe == 0, fd = NULL
	struct s_parse *previous;
    struct s_parse *next;
}   t_parse;
/*
no redirection  0
REDIRECT_IN,	1
HEREDOC,	2

no redirection  0
REDIRECT_OUT,	1
APP_M		2

no pipe 0;
pipe 1;
*/

/* Functions */


void	print_list(t_list *s);
t_list	*ft_str_lexer_1(char *str, t_list *list);
//t_list	*ft_str_lexer_2(char *str, t_list *list, int i);
//char *ft_redirection_0(char *str, t_list *list);

//char *ft_redirection_0(char *str);
//char *ft_quote_0(char *str);
char *ft_space(char *str, t_list **list, int c);
char *ft_doller(char *str, t_list **list, int c);
char *ft_pipe(char *str, t_list **list, int c);
char *ft_double_quote_1(char *str, t_list **list, int c);
char *ft_single_quote_2(char *str, t_list **list, int c);
char *ft_newline(char *str, t_list **list, int c);
char *ft_esc(char *str, t_list **list, int c);

char *ft_redirection_1(char *str, t_list **list, int c);
char *ft_redirection_2(char *str, t_list **list, int c);
char *ft_word(char *str, t_list **list);

int	ft_strlen(char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	print_parse(t_parse *s);
t_parse *parser_list(t_list *list);

#endif
