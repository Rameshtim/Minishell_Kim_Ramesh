/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:44:42 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/17 11:44:43 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void ft_lstadd_back(t_list **list, t_list *new, enum e_token type, enum e_state state)
{
    t_list *tmp;

    if (!list || !new)
        return ;
    new->type = type;
    new->state = state;
    new->next = NULL;
    if (!*list)
    {
		*list = new;
        return ;
    }
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int ft_strchr_len(char *str, int c)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        if (str[i] == c)
            count++;
        if (str[i] == c && str[i + 1] != c)
            break ;
        i++;
    }
    return (count);
}

int ft_strchr_len_2(char *str, int c)
{
    int i = 1;

    while (str[i])
    {
        if (str[i] == c)
            break ;
        i++;
    }
    return (i);
}

int ft_strchr_word_len(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
            count++;
        if (str[i] >= 33 && str[i] <= 126 && ((str[i + 1] == ' ') 
            || (str[i + 1] == '\"') || (str[i + 1] == '\'')))
            break ;
        i++;
    }
    return (count);
}

char *ft_space(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    printf("space\n");
    ft_lstadd_back(list, temp, SPACE_, OTHER);
    return (str);
}

char *ft_doller(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    printf("\tdoller\n");
    ft_lstadd_back(list, temp, DOLLER, OTHER);
    return (str);
}

char *ft_pipe(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    printf("\tpipe\n");
    ft_lstadd_back(list, temp, PIPE, OTHER);
    return (str);
}

char *ft_double_quote_1(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    if (str[ft_strchr_len_2(str, c)] == '\0')
    {
        free(temp); 
        return (ft_word(str, list));
    }
    temp->input = ft_substr(str, 0, ft_strchr_len_2(str, c) + 1);
    str = str + ft_strchr_len_2(str, c) + 1;
    temp->len = ft_strlen(temp->input);
    printf("\tdouble_quote\n");
    ft_lstadd_back(list, temp, D_QUOTE, IN_DQUOTE);
    return (str);
}

char *ft_single_quote_2(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    if (str[ft_strchr_len_2(str, c)] == '\0')
    {
        free(temp); 
        return (ft_word(str, list));
    }
    temp->input = ft_substr(str, 0, ft_strchr_len_2(str, c) + 1);
    str = str + ft_strchr_len_2(str, c) + 1;
    temp->len = ft_strlen(temp->input);
    ft_lstadd_back(list, temp, S_QUOTE, IN_SQUOTE);
    printf("\tsingle_quote\n");
    return (str);
}


char *ft_newline(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    printf("\tnew_line\n");
    ft_lstadd_back(list, temp, NEW_LINE, OTHER);
    return (str);
}

char *ft_esc(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    printf("\tesc\n");
    ft_lstadd_back(list, temp, ESC_, OTHER);
    return (str);
}

char *ft_redirection_2(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    if (c == 60)//<< here document, put the input until the tag enters
    {
        printf("\theredoc\n");
        ft_lstadd_back(list, temp, HEREDOC, OTHER);
    }
    else if (c == 62)//>> redirct output with append mode
    {
        printf("\tappendmode\n");
        ft_lstadd_back(list, temp, APPMODE, OTHER);
    }
    return (str);
}

char *ft_redirection_1(char *str, t_list **list, int c)
{
    t_list *temp;

    temp = *list;
    if (ft_strchr_len(str, c) == 2)
        return (ft_redirection_2(str, list, c));
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_len(str, c));
    str = str + ft_strchr_len(str, c);
    temp->len = ft_strlen(temp->input);
    if (c == 60)//< redirect input
    {
        printf("\tredirectionin\n");
        ft_lstadd_back(list, temp, REDIRECT_IN, OTHER);
    }
    else if (c == 62)//> redirect output
    {
        printf("\tredirectionout\n");
        ft_lstadd_back(list, temp, REDIRECT_OUT, OTHER);
    }
    return (str);
}

char *ft_word(char *str, t_list **list)
{
    t_list *temp;

    temp = *list;
    temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
    temp->input = ft_substr(str, 0, ft_strchr_word_len(str));
    str = str + ft_strchr_word_len(str);
    temp->len = ft_strlen(temp->input);
    printf("\t\tword\n");
    ft_lstadd_back(list, temp, WORD, OTHER);
    return (str);
}