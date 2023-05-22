/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:10:29 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/18 16:12:20 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
//# include "libft.h"
# include <stdlib.h>//free, malloc
# include <unistd.h>//read, write
# include <stdio.h>//printf
# include <readline/readline.h>//readline
# include <readline/history.h>//add_history
# include <signal.h>//handle_signals
# include <termios.h>//control terminal Input and Output
# include <string.h>//
# include <stdbool.h>//
# include <sys/types.h>
# include <sys/wait.h>
# define CLEAR_SCREEN "\033[?1049h\033[H"

/*typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/
void	initialize_readline(void);
int	ft_error(int k, char *str);
void	check_vvod(char *com, t_list *all, char **env);
int	main(int argc, char *argv[], char **env);
char	**ft_free_split(char **str);
int	ft_strcmp(const char *s1, const char *s2);
t_list *change_oldpwd(t_list *all);
void	do_cd_return(t_list *all);
void	do_cd_sign(char *str, t_list *all);
void	do_cd_without(t_list *all);
t_list	*do_cd(char **str, t_list *all);
int	do_also(char **com, t_list *all, char **env);
char	*find_path(char *com, t_list *all);
t_list	*parse_env(t_list *env, char *name);
int	kol_args(char **str);
t_list	*add_list_env(char **env);
t_list	*list_add_back(t_list *list, void *content);
t_list	*create_list(void *content);
#endif
