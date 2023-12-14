/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:27:12 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/12 14:18:52 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_min(t_push_swap **stack)
{
	long		i;
	t_push_swap	*tmp;

	tmp = *stack;
	i = tmp->nb;
	while (tmp)
	{
		if (i > tmp->nb)
			i = tmp->nb;
		tmp = tmp->next;
	}
	return (i);
}

long	get_max(t_push_swap **stack)
{
	long		i;
	t_push_swap	*tmp;

	tmp = *stack;
	i = tmp->nb;
	while (tmp)
	{
		if (i < tmp->nb)
			i = tmp->nb;
		tmp = tmp->next;
	}
	return (i);
}

int	get_index(t_push_swap **stack, long nb)
{
	int			i;
	t_push_swap	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp->next && tmp->nb != nb)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	get_index_place_b(t_push_swap *stack, long nb)
{
	int			i;
	t_push_swap	*tmp;

	i = 1;
	if (nb > stack->nb && nb < ft_lstlast(stack)->nb)
		i = 0;
	else if (nb > get_max(&stack) || nb < get_min(&stack))
		i = get_index(&stack, get_max(&stack));
	else
	{
		tmp = stack->next;
		while (stack->nb < nb || tmp->nb > nb)
		{
			stack = stack->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
