/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramesh <ramesh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:03 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 13:16:39 by ramesh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H
# include "../minishell1.h"
//# include "../libft/libft.h"

t_list	*ft_listdup(t_list *lst);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_lst_sort_str(t_list **lst, int (*op)(char *, char *));
void	ft_lstdel_int(void *data);
char	*ft_strcpy(char	*dest, const char *src);
char	*ft_strcat(char *dest, char *src);
int is_quote(char c);
void	ft_lstdel_first(t_list **lst, void (*del)(void*));
void	ft_lstdel_last(t_list *lst, void (*del)(void*));
void	ft_dlstclear(t_dlist **lst, void (*del)(void*));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void*));


#endif