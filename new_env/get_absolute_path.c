/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:54 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/19 17:38:25 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	add_slash(char ***path_env_split)
{
	int		i;
	char	*path;
	int		len;
	char	*new_path;

	i = 0;
	while ((*path_env_split))
	{
		path = (*path_env_split)[i];
		len = ft_strlen(path);
		if (path[len - 1] != '/')
		{
			new_path = ft_strjoin(path, "/");
			free(path);
			(*path_env_split)[i] = new_path;
		}
		i++;
	}
}

void	free_arr(void **ptr)
{
	int	i;
	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**get_path_env_split(void)
{
	char	*path_env;
	char	**path_env_split;

	path_env = ft_getenv("PATH");
	if (!path_env)
		return (0);
	path_env_split = ft_split(path_env, ":");
	free(path_env);
	if (!path_env_split)
		quit_program(EXIT_FAILURE);
	add_slash(&path_env_split);
	//add a "/" at the end of every path that is splitted.
	//like in path it will be /usr/bin so we make /usr/bin/
	return (path_env_split);
}


//Remember to compile your program with the appropriate compiler flags, such as 
//-std=c11 or -std=c99, to ensure compatibility and access to the necessary system headers
char	*get_correct_path(char *program_name, char **path_env_split)
{
	char	*absolute_path;
	int		i;
	struct stat	statbuf;

	i = 0;
	while (path_env_split[i])
	{
		absolute_path = ft_strjoin(path_env_split[i], program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE);
		if (stat(absolute_path, &statbuf) == EXIT_SUCCESS)
			break;
		free (absolute_path);
		i++;
	}
	if (!path_env_split[i])
	{
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE);
	}
	return (absolute_path);
}

char	*get_absolute_path(char *program_name)
{
	char	**path_env_split;
	char	*absolute_path;

	path_env_split = get_path_env_split();
	if (!path_env_split)
	{
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE);
		//if unset PATH was executed throw error and quit.
	}
	else
	{
		absolute_path = get_correct_path(program_name, path_env_split);
		free_arr((void **)path_env_split);
	}
	return (absolute_path);
}