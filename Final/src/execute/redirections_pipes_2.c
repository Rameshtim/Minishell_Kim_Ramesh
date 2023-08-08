/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:11:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 11:11:37 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections_pipes_2.h"

int	open_heredoc_file(t_redir *redir, int prev_fd, int flags, mode_t permissions, t_msh *g_msh)
{
	char	*file_name;
	int		new_fd;

	if (prev_fd != -2)
		close(prev_fd);
	file_name = redir->direction;
	new_fd = open(file_name, flags, permissions);
	if (new_fd == -1)
	{
		write_msh_exec_error(file_name, strerror(errno));
		g_msh->exit_status = errno;
	}
	else
	{
		dup2(new_fd, STDIN_FILENO);
		close(new_fd);
		unlink(file_name);
	}
	return (new_fd);
}

void read_heredoc_file(t_redir *redir, t_msh *g_msh)
{
    char *whole_str;
    char *str;
    char *tmp;
    char *name;

	whole_str = ft_strdup("");
	name = (char *)redir->direction;
    while (1) 
	{
        str = readline("heredoc>");
        if (!str)
            break;
        if (!ft_strcmp(str, (char *)name)) 
		{
            free(str);
            break;
        }
        replace_vars_with_values(&str, g_msh);
        tmp = ft_strjoin(whole_str, str);
        free(str);
        whole_str = ft_strjoin(tmp, "\n");
        free(tmp);
    }
    printf("%s", whole_str);
}
