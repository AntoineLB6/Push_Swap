/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:06:16 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/14 09:25:12 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_doublons(t_push_swap **nbrs, char *str)
{
	long		nb;
	t_push_swap	*tmp;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	if (!nbrs)
		return (0);
	tmp = *nbrs;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	lst_init(t_push_swap **lst, char *str)
{
	t_push_swap	*new;

	if (check_doublons(lst, str))
		return (-1);
	new = lst_new(ft_atoi(str));
	if (!new)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

t_push_swap	*lst_new(long nb)
{
	t_push_swap	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_push_swap	*ft_lstlast(t_push_swap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_push_swap **lst, t_push_swap *elem)
{
	t_push_swap	*tmp;

	if (!lst || !elem)
		return ;
	if (!*lst)
		*lst = elem;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = elem;
	}
}
