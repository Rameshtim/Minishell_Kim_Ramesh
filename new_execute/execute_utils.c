/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:22:58 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/25 20:22:58 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	is_builtin(t_list *tokens)
{
	int	check;
	char	*program_name;

	program_name = tokens->content;
	if (ft_strcmp(program_name, "exit") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "echo") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "env") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "cd") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "pwd") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "export") == 0)
		check = 1;
	else if (ft_strcmp(program_name, "unset") == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

int	has_absolute_path(char *first_token)
{
	//check absolute path like /bin/ls
	if (*first_token == '/')
		return (1);
	return (0);
}

int	has_relative_path(char *first_token)
{
	//check relative path like ./a.out
	if (*first_token == '.')
		return (1);
	return (0);
}

char	**convert_list_to_arr(t_list *lst)
{
	char	**str;
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(lst);
	str = ft_calloc(len + 1, sizeof(char *));
	while (i < len)
	{
		str[i] = (char *)lst->content;
		lst = lst->next;
		i++;
	}
	return (str);
}