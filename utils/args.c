/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:14:08 by antoine           #+#    #+#             */
/*   Updated: 2023/12/13 12:13:29 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_strnbrs(t_push_swap **nbrs, char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == 32 || (argv[i] >= 9 && argv[i] <= 13))
			i++;
		else if ((argv[i] >= '0' && argv[i] <= '9')
			|| argv[i] == '-' || argv[i] == '+')
		{
			if (lst_init(nbrs, argv + i) == -1)
				return (-1);
			while ((argv[i] >= '0' && argv[i] <= '9')
				|| argv[i] == '-' || argv[i] == '+')
				i++;
		}
		else
			return (-1);
	}
	return (0);
}

int	get_argsnbrs(int argc, char **argv, t_push_swap **nbrs)
{
	int			i;

	i = 1;
	*nbrs = NULL;
	while (i < argc)
	{
		if (get_strnbrs(nbrs, argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	get_args(int argc, char **argv, t_push_swap **nbrs)
{
	if (get_argsnbrs(argc, argv, nbrs) == -1)
		return (-1);
	return (0);
}
