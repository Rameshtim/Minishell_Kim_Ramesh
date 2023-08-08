/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:52 by rtimsina          #+#    #+#             */
/*   Updated: 2023/08/08 13:47:29 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	new->next = *lst;
	new->prev = 0;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}