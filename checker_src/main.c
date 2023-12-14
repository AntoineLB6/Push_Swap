/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:09:00 by marvin            #+#    #+#             */
/*   Updated: 2023/12/14 09:49:32 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, 1);
		return ;
	}
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) <= 5)
	{
		sort_under_five(stack_a, stack_b);
		return ;
	}
	sortb(stack_a, stack_b);
	go_to_min(stack_b, 'b');
	rb(stack_b, 1);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

int	main(int argc, char **argv)
{
	t_push_swap	*nums;
	t_push_swap	*stack_b;

	stack_b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		return (1);
	if (get_args(argc, argv, &nums) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(nums))
		ft_sort(&nums, &stack_b);
	if (is_sorted(nums) && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&nums);
	free_lst(&stack_b);
	return (0);
}
