/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:50:06 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 09:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	if (wr)
		write(1, "ra\n", 3);
}

void	rb(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	if (wr)
		write(1, "rb\n", 3);
}

void	rr(t_push_swap **stack_a, t_push_swap **stack_b, int wr)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (wr)
		write(1, "rr\n", 3);
}
