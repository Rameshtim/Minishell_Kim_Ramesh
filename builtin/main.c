/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:42:03 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/18 16:07:18 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_error(int k, char *str)
{
	if (k == 1)
		ft_putstr_fd("using: unsetenv [name]\n", 1);
	if (k == 2)
		ft_putstr_fd("using: setenv [name] [value]\n", 1);
	if (k == 3)
	{
		ft_putstr_fd("cd: string not in pwd: ", 1);
		ft_putstr_fd(str, 1);
		write (1, "\n", 1);
	}
	if (k == 4)
	{
		ft_putstr_fd("minishell: command not found: ", 1);
		ft_putstr_fd(str, 1);
		write (1, "\n", 1);
	}
	if (k == 5)
	{
		ft_putstr_fd("cd: no such file or directory: ", 1);
		ft_putstr_fd(str, 1);
		write (1, "\n", 1);
	}
	return (1);
}

static void my_int(int ret)
{
	(void)ret;
	ft_putstr_fd("\n$> ", 1);
}

/* static void do_help(void)
{
	ft_putstr_fd("Available commands:\n", 1);
	ft_putstr_fd("clear\ncd\necho\nsetenv\nunsetenv\nenv\nexit", 1);
}
 */
void	check_vvod(char *com, t_list *all, char **env)
{
	char	**my_com;
	
	my_com = env;
	if ((my_com = ft_split(com, ' ')) && *my_com)
	{
		if (!(ft_strncmp(my_com[0], "clear", 5)))
			ft_putstr_fd(CLEAR_SCREEN, 1);
		else if (!(ft_strncmp(my_com[0], "cd", 2)))
			all = do_cd(my_com, all);
	}
}

int	main(int argc, char *argv[], char **env)
{
	char	*command;
	t_list	*all;
	char	**split;
	int		c;

	(void)argc;
	*argv = NULL;
	all = add_list_env(env);
	while ((c = -1))
	{
		signal(SIGINT, my_int);
		initialize_readline();
		if (!(command = readline("$> ")))
			return (EXIT_FAILURE);
		add_history(command);
		if (!(split = ft_split(command, ';')))
			return (0);
		while (split[++c])
			check_vvod(split[c], all, env);
		ft_free_split(split);
		free(command);
	}
	return (0);
}