/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:03 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/20 16:15:01 by rtimsina         ###   ########.fr       */
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

#endif