/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:30:43 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/08 22:00:08 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_calcul_b(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int			i;
	t_push_swap	*tmp;

	tmp = *stack_a;
	i = instr_to_rarb(stack_a, stack_b, tmp->nb);
	while (tmp)
	{
		if (i > instr_to_rarb(stack_a, stack_b, tmp->nb))
			i = instr_to_rarb(stack_a, stack_b, tmp->nb);
		if (i > instr_to_rrarrb(stack_a, stack_b, tmp->nb))
			i = instr_to_rrarrb(stack_a, stack_b, tmp->nb);
		if (i > instr_to_rrarb(stack_a, stack_b, tmp->nb))
			i = instr_to_rrarb(stack_a, stack_b, tmp->nb);
		if (i > instr_to_rarrb(stack_a, stack_b, tmp->nb))
			i = instr_to_rarrb(stack_a, stack_b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int	instr_to_rarb(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = get_index_place_b(*stack_b, nb);
	if (i < get_index(stack_a, nb))
		i = get_index(stack_a, nb);
	return (i);
}

int	instr_to_rrarrb(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = 0;
	if (get_index_place_b(*stack_b, nb) != 0)
		i = ft_lstsize(*stack_b) - get_index_place_b(*stack_b, nb);
	if ((i < ft_lstsize(*stack_a) - get_index(stack_a, nb))
		&& get_index(stack_a, nb))
		i = ft_lstsize(*stack_a) - get_index(stack_a, nb);
	return (i);
}

int	instr_to_rarrb(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = ft_lstsize(*stack_b) - get_index_place_b(*stack_b, nb);
	i += get_index(stack_a, nb);
	return (i);
}

int	instr_to_rrarb(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = ft_lstsize(*stack_a) - get_index(stack_a, nb);
	i += get_index_place_b(*stack_b, nb);
	return (i);
}
