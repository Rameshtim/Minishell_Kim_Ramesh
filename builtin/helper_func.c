/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:15:48 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/18 16:01:47 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	kol_args(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	**ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str;
	unsigned char	*src;

	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (*str == *src && *str)
	{
		str++;
		src++;
	}
	return (*str - *src);	
}

t_list	*parse_env(t_list *env, char *name)
{
	char	**split;

	while (env)
	{
		split = ft_split(env->content, '=');
		if (!ft_strcmp(split[0], name))
		{
			ft_free_split(split);
			env = env->next;
		}
	}
	return (NULL);
}

char	*find_path(char *com, t_list *all)
{
	t_list	*path_lst;
	char	**split;
	char	*str;
	int		i;

	if ((path_lst = parse_env(all, "PATH")))
	{
		split = ft_split(path_lst->content + 5, ':');
		i = -1;
		while (split[++i])
		{
			str = ft_strjoin(ft_strjoin(split[i], "/"), com);
			if (!access(str, X_OK))
			{
				ft_free_split(split);
				return (str);
			}
			free(str);
		}
		ft_free_split(split);
	}
	return (NULL);
}

int	do_also(char **com, t_list *all, char **env)
{
	pid_t	pid;
	char	*path;

	if (!(pid = fork()))
	{
		if (access(com[0], X_OK))
		{
			if ((path = find_path(com[0], all)))
			{
				free(com[0]);
				com[0] = path;
				free(path);
				execve(com[0], com, env);
			}
			else
			{
				wait(&pid);
				return (ft_error(4, com[0]));
			}
		}
		else
			execve (com[0], com, env);
	}
	wait(&pid);
	return (0);
}

t_list	*list_add_back(t_list *list, void *content)
{
	t_list	*item;
	t_list	*ret;

	if (!list)
		return(create_list(content));
	ret = list;
	while (list->next)
		list = list->next;
	if (!(item = malloc(sizeof(t_list))))
		return (NULL);
	item->content = content;
	item->next = NULL;
	list->next = item;
	return (ret);
}

t_list	*create_list(void *content)
{
	t_list	*ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}