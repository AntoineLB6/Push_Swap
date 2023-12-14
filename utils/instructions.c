/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:19:41 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 07:54:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (wr)
		write(1, "sa\n", 3);
}

void	sb(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (wr)
		write(1, "sb\n", 3);
}

void	ss(t_push_swap **stack_a, t_push_swap **stack_b, int wr)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (wr)
		write(1, "ss\n", 3);
}

void	pa(t_push_swap **stack_a, t_push_swap **stack_b, int wr)
{
	t_push_swap	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (wr)
		write(1, "pa\n", 3);
}

void	pb(t_push_swap **stack_a, t_push_swap **stack_b, int wr)
{
	t_push_swap	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (wr)
		write(1, "pb\n", 3);
}
