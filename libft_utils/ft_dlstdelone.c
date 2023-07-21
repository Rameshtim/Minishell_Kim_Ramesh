/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:14:44 by rtimsina          #+#    #+#             */
/*   Updated: 2023/07/21 16:14:44 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	ft_dlstdelone(t_dlist *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}