/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:11:40 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/18 16:01:01 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_list *change_oldpwd(t_list *all)
{
	char	*str;
	t_list	*to_del;
	t_list	*lst;
	char	*pwd;

	lst = all;
	if ((to_del = parse_env(all, "OLDPWD")))
	{
		while (all->next != to_del)
			all = all->next;
		all->next = to_del->next;
		free(to_del->content);
		free(to_del);		
	}
	if (!(pwd = getcwd(NULL, 0)))
		return (all);
	str = ft_strjoin(ft_strjoin("OLDPWD", "="), pwd);
	lst = list_add_back(all, str);
	free(pwd);
	return (lst);
}

void	do_cd_return(t_list *all)
{
	t_list	*lst;
	char	*src;
	
	if ((lst = parse_env(all, "OLDPWD")))
	{
		src = ft_strdup(lst->content + 7);
		change_oldpwd(all);
		chdir(src);
		free(src);
	}
}

void	do_cd_sign(char *str, t_list *all)
{
	t_list	*lst;
	char	*src;

	if ((lst = parse_env(all, "HOME")))
	{
		if (str[1])
			src = ft_strjoin(lst->content + 5, str + 1);
		else
			src = ft_strdup(lst->content + 5);
		all = change_oldpwd(all);
		chdir(src);
		free(src);
	}
}

void	do_cd_without(t_list *all)
{
	t_list	*lst;
	char	*src;

	if ((lst = parse_env(all, "HOME")))
	{
		src = ft_strdup(lst->content + 5);
		all = change_oldpwd(all);
		chdir(src);
		free(src);
	}
}

t_list	*do_cd(char **str, t_list *all)
{
	if (kol_args(str) > 2)
		ft_error(3, str[1]);
	if (str[1] && !ft_strcmp("-", str[1]))
		do_cd_return(all);
	else if (str[1] && str[1][0] == '~')
		do_cd_sign(str[1], all);
	else if (str[1] && ft_strcmp("~", str[1]) && ft_strcmp("-", str[1]))
	{
		all = change_oldpwd(all);
		if (chdir(str[1]))
			ft_error(5, str[1]);
	}
	else
		do_cd_without(all);
	return (all);
}