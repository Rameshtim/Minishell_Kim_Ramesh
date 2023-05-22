/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:24:49 by hongbaki          #+#    #+#             */
/*   Updated: 2023/05/17 16:24:50 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
/*
int		count_pipes(t_list *list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->type == PIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*get_next_pipe(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp && tmp->type != PIPE)
		tmp = tmp->next;
	return (tmp);
}
*/
/* static t_parse *get_parse_bottom(t_parse *node)
{
    while(node && node->next != NULL)
        node = node->next;
    return (node);
} */
/*
static int		count_word1(t_list *list)
{
	t_list	*tmp;
	int 	i;

	i = 0;
	tmp = list;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == WORD)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static t_list		*count_args1(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp && tmp->type != PIPE)
		tmp = tmp->next;
	return (tmp);
}
*/

/* static t_list		*count_args2(t_list *list)
{
	while (list && list->type != PIPE)
		list = list->next;
	return (list);
} */





t_parse *init_parse_node(t_parse *parse_node, int i)
{
	parse_node->command = malloc(sizeof(char *) * (i + 1));
	if (!parse_node->command)
		return (NULL);
	parse_node->command[i] = 0;
	parse_node->redirection_in = 0;
	parse_node->redirection_out = 0;
	parse_node->infilepath = NULL;
	parse_node->outfilepath = NULL;
	parse_node->pipe = 0;
	//parse_node->fd[] = NULL;
	parse_node->previous = 0;
	parse_node->next = 0;
	return (parse_node);
}

int		count_word(t_list **list)
{
	t_list	*tmp;
	int 	i;

	i = 0;
	tmp = *list;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == WORD)
			i++;
		tmp = tmp->next;
	}
	printf("count_word %d", i);
	return (i);
}

t_list *find_next_word(t_list *list)
{
	while(list)
	{
		if (list->type == WORD)
			break ;
		list = list->next;
	}
	return (list);
}

void parse_new_node_redirection(t_parse *parse_node, t_list **list)
{
	t_list *temp;

	temp = *list;
		if (temp->type == REDIRECT_IN)
		{
			parse_node->redirection_in = 1;
			parse_node->infilepath = find_next_word(temp)->input;
		}
		else if (temp->type == HEREDOC)
		{
			parse_node->redirection_in = 2;
			parse_node->infilepath = find_next_word(temp)->input;
		}
		else if (temp->type == REDIRECT_OUT)
		{
			parse_node->redirection_out = 1;
			parse_node->outfilepath = find_next_word(temp)->input;
		}
		else if (temp->type == APPMODE)
		{
			parse_node->redirection_out = 2;
			parse_node->outfilepath = find_next_word(temp)->input;
		}
}

t_parse *parser_list(t_list *list)
{
	int	i;
	t_list *temp;
	t_parse *parse_node;

	i = 0;
	parse_node = (t_parse *)malloc(sizeof(t_parse));
	if (!parse_node)
		return (NULL);
	parse_node = init_parse_node(parse_node, count_word(&list));
	temp = list;
	while (temp)
	{
		if (temp->type == WORD)
			parse_node->command[i++] = list->input;
		parse_node->size = i;
		parse_new_node_redirection(parse_node, &temp);
		if (temp->type == PIPE)
		{
			parse_node->pipe = 1;
			break ;
		}
		temp = temp->next;
	}
	return (parse_node);
}

void	print_parse(t_parse *str)
{
	t_parse	*temp;

	temp = str;
	printf("\n------------------------  parser  -------------------------\n");
	if (!str)
	{
		printf("PARSE empty!\n");
		return ;
	}
	while (temp)
	{
		/* printf("c[0]: %s\n", temp->command[0]);
		printf("c[1]: %s size: %i\n", temp->command[1], temp->size);
		//printf("command[2]: %s size: %i", temp->command[2], temp->size);
		printf("re_in: %i re_out: %i\n", temp->redirection_in, temp->redirection_out);
		printf("inpath: %s outpath: %s\n", temp->infilepath, temp->outfilepath); */
		temp = temp->next;
	}
	printf("----------------------------------------------------------\n\n");
}

/*static void ft_add_tail_parse(t_parse **parse, t_parse *parse_node)
{
    t_parse *bottom;

    if (!parse_node)
        return ;
    parse_node->next = 0;
    if (!*parse)
    {
		*parse = parse_node;
        return ;
    }
	bottom = get_parse_bottom(*parse);
    bottom->next = parse_node;
    parse_node->previous = bottom;
}

 void parse_integration(t_list **list, t_parse **parse)
{
	t_list *temp;
	t_parse *parse_node;

	temp = *list;
	while(temp)
	{
		parse_node = parse_new_node(temp);
		ft_add_tail_parse(parse, parse_node);
		temp = temp->next;
	}
} */

