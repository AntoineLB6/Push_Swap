/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:57:42 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/04 16:21:12 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_push_swap *lst)
{
	int	i;

	i = lst->nb;
	while (lst)
	{
		if (i > lst->nb)
			return (0);
		i = lst->nb;
		lst = lst->next;
	}
	return (1);
}
