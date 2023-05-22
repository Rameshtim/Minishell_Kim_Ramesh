/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:24:06 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/17 07:24:06 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/* int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
} */

/* 

char *ft_quote_0(char *str)
{
	t_list *list;

	if (*str == '\"')
		str = ft_double_quote_1(str, &list, '\"');
	else
		str = ft_single_quote_2(str, &list, '\'');
	return (str);
} 

char *ft_redirection_0(char *str)
{
	t_list *list;

	if (*str == '<')
		str = ft_redirection_1(str, &list, '<');
	else
		str = ft_redirection_1(str, &list, '>');
	return (str);
}*/


t_list	*ft_str_lexer_1(char *str, t_list *list)
{
	while(*str)
	{
		if (*str == ' ')
			str = ft_space(str, &list, ' ');
		else if (*str == '\"')
			str = ft_double_quote_1(str, &list, '\"');
		else if (*str == '\'')
			str = ft_single_quote_2(str, &list, '\'');
		else if (*str == '$')
			str = ft_doller(str, &list, '$');
		else if (*str == '|')
			str = ft_pipe(str, &list, '|');
		else if (*str == '\n')
			str = ft_newline(str, &list, '\n');
		else if (*str == '\\')
			str = ft_esc(str, &list, '\\');
		else if (*str == '<')
			str = ft_redirection_1(str, &list, '<');
		else if (*str == '>')
			str = ft_redirection_2(str, &list, '>');
		else
			str = ft_word(str, &list);
	}
	return (list);
}

t_list *lexer_list(t_list *list)
{
	char *str;
	int	i = 0;

	str = readline("[shell]");
	printf("\n------------------------lexer_list-------------------------\n");
	while (str[i] == ' ')
		i++;
	list = ft_str_lexer_1(str, list);
	printf("----------------------------------------------------------\n\n");
	return (list);
}

void	print_list(t_list *str)
{
	t_list	*temp;

	temp = str;
	printf("\n---------------------------   list   ------------------------\n");
	printf("<input>\t\t\t\t\t<len>\t<type>\t<state>\n");
	if (!str)
	{
		printf("list empty!\n");
		return ;
	}
	while (temp)
	{
		printf("%s\t\t\t\t\t%i\t%i\t%i\n", temp->input, temp->len, temp->type, temp->state);
		temp = temp->next;
	}
	printf("--------------------------------------------------------------\n\n");
}

int	main()
{
	t_list *list;
	t_parse *parse;

	list = NULL;
	parse = NULL;
	list = lexer_list(list);
	parse = parser_list(list);
	print_list(list);
	print_parse(parse);
}

/*
t_list	*ft_str_lexer_1(char *str, t_list *list)
{
	while(*str)
	{
		if (*str == ' ')
			str = ft_space(str, &list, ' ');
		else if (*str == '$')
			str = ft_doller(str, &list, '$');
		else if (*str == '|')
			str = ft_pipe(str, &list, '|');
		else if (*str == '\"' || *str == '\'')
			str = ft_quote_0(str);
		else if (*str == '\n')
			str = ft_newline(str, &list, '\n');
		else if (*str == '\\')
			str = ft_esc(str, &list, '\\');
		else if (*str == '<' || *str == '>')
			str = ft_redirection_0(str);
		else
			str = ft_word(str, &list);
	}
	return (list);
}*/
