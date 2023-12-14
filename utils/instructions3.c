/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:50:06 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 13:16:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;
	t_push_swap	*last;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (wr)
		write(1, "rra\n", 4);
}

void	rrb(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;
	t_push_swap	*last;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (wr)
		write(1, "rrb\n", 4);
}

void	rrr(t_push_swap **stack_a, t_push_swap **stack_b, int wr)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (wr)
		write(1, "rrr\n", 4);
}
