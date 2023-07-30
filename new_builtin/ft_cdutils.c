/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:21 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/12 16:20:38 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <sys/stat.h>

//EXIT_SUCCESS = 0 and EXIT_FAILURE = Failure code.

int	cd_error_message(char *builtin, char *error)
{
	write_minishell_exec_error(builtin, error);
	return (EXIT_FAILURE);
}

int	has_x_permission(char *path)
{
	struct stat statbuf;
	//struct stat is in <sys/stat.h>
	
	if (stat(path, &statbuf) == EXIT_SUCCESS)
	{//stat(path, &statbuf) is used to retrieve the file info for the
	//specified path and store it in statbuf. returns 0 on success
		if (statbuf.st_mode & S_IXUSR)
		//st_mode Represents the file type and permissions.
		//S_IXUSR is a flag that represents the execute permission for owner.
			return (1);
		else
		{
			write_minishell_exec_arg_error("cd", path, "Permission denied");
			return (0);
		}
	}
	else
	{
		write_minishell_exec_arg_error("cd", path, strerror(errno));
		return (0);
	}
}

int	other_invalid_error(char *builtin, int error, char *arg)
{
	write_minishell_exec_arg_error(builtin, arg, strerror(error));
	return (EXIT_FAILURE);
}

int	cd_env_error_check(char *env)
{
	DIR		*dirp;
	//DIR is a data type representing a directory stream from <dirent.h>
	char	*arg;
	int		status;

	arg = ft_getenv(env);
	if (arg == NULL)
		status = cd_error_message("cd", "HOME not set");
	else if (*arg == '\0')
		status = EXIT_SUCCESS;
	else
	{
		if (!has_x_permission(arg))
			return (EXIT_FAILURE);
		dirp = opendir(arg);
		if (dirp == NULL)
			status = other_invalid_error("cd", errno, arg);
		else
		{
			status = EXIT_SUCCESS;
			closedir (dirp);
		}
		free (arg);
	}
	return (status);
}

int	cd_path_error_check(char *path)
{
	DIR	*dirp;
	int	status;

	if (!has_x_permission(path))
		return (EXIT_FAILURE);
	dirp = opendir(path);
	if (dirp == NULL)
		status = other_invalid_error("cd", errno, path);
	else
	{
		status = EXIT_SUCCESS;
		closedir(dirp);
	}
	return (status);
}